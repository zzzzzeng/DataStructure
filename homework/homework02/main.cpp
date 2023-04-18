#include"../../Vector/Vector/Stack.h"

#include <stdio.h>
#include<string.h>

#define N_OPTR 9 //���������
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //���������
//�ӡ������ˡ������˷����׳ˡ������š������š���ʼ������ֹ��

const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
	/*              |-------------------- �� ǰ �� �� �� --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

int choose(char c) {

	switch (c)
	{
	case '+':return ADD;
	case '-':return SUB;
	case '*':return MUL;
	case '/':return DIV;
	case '^':return POW;
	case '!':return FAC;
	case '(':return L_P;
	case ')':return R_P;
	case '\0':return EOE;
	default:exit(-1);
	}
}
char orderBetween(char c1, char c2) { //�ж����ȶ�
	return pri[choose(c1)][choose(c2)];
}

float readNumber(char*& S, Stack<float>& opnd) {
	float x = 0.0;
	bool point = false;//�ж��Ƿ�ΪС��
	int i = 0;//��С������λ��
	while (isdigit(*S) || *S == '.') {
		if (*S != '.') {
			if (point == false) 	x = x * 10 + (*(S++) - 48);//��ȥ48,ASCIIת������
			if (point == true) { x = x * 10 + (*(S++) - 48); i++; }
		}
		else { S++; point = true; }
	}
	int temp = 1;
	for (int j = 0; j < i; j++) temp *= 10;
	x = x / temp;
	opnd.push(x);//ѹ�������ջ
	return x;
}

float fac(int n) { return (2 > n) ? 1 : n * fac(n - 1); }
float calcu(char optr, float opnd) { return fac(opnd); }
float calcu(float opnd1, char op, float opnd2) {
	float result = 1;
	switch (op) //�ж������
	{
	case '+': {result = opnd1 + opnd2; return result; }
	case '-': {result = opnd1 - opnd2; return result; }
	case '*': {result = opnd1 * opnd2; return result; }
	case '/': {result = opnd1 / opnd2; return result; }
	case '^': {for (int i = 0; i < opnd2; i++) result *= opnd1; return result; }
	}//switch
}


float evaluate(char* S) {
	Stack<float> opnd; Stack<char> optr;
	optr.push('\0');
	while (!optr.empty()) {
		if (isdigit(*S)) {
			readNumber(S, opnd);
			//append(RPN, opnd.top());
		}
		else
			switch (orderBetween(optr.top(), *S)) {
			case '<':
				optr.push(*S); S++;
				break;
			case '=':
				optr.pop(); S++;
				break;
			case '>': {
				char op = optr.top(); optr.pop();
				if ('!' == op) {
					
					float pOpnd = opnd.top(); opnd.pop();
					opnd.push(calcu(op, pOpnd));//ʵʩһԪ����
				}
				else {
					float pOpnd2 = opnd.top(); opnd.pop();
					float pOpnd1 = opnd.top(); opnd.pop();
					opnd.push(calcu(pOpnd1, op, pOpnd2));//ʵʩ��Ԫ����
				}
				break;
			}
			default:exit(-1);
			}//switch
	}//while
	float Result = opnd.top();//��ת�������,��pop
	opnd.pop();
	return Result;//�������������ļ�����
}

int main() {
	int i;
	char test[10];
	cout << "������" << endl;
	
	cin >> test;
	
	cout<<evaluate(test);
	return 0;
}



