#include"../../Vector/Vector/Stack.h"

#include <stdio.h>
#include<string.h>

#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
	/*              |-------------------- 当 前 运 算 符 --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
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
char orderBetween(char c1, char c2) { //判断优先度
	return pri[choose(c1)][choose(c2)];
}

float readNumber(char*& S, Stack<float>& opnd) {
	float x = 0.0;
	bool point = false;//判断是否为小数
	int i = 0;//计小数点后的位数
	while (isdigit(*S) || *S == '.') {
		if (*S != '.') {
			if (point == false) 	x = x * 10 + (*(S++) - 48);//减去48,ASCII转成数字
			if (point == true) { x = x * 10 + (*(S++) - 48); i++; }
		}
		else { S++; point = true; }
	}
	int temp = 1;
	for (int j = 0; j < i; j++) temp *= 10;
	x = x / temp;
	opnd.push(x);//压入操作数栈
	return x;
}

float fac(int n) { return (2 > n) ? 1 : n * fac(n - 1); }
float calcu(char optr, float opnd) { return fac(opnd); }
float calcu(float opnd1, char op, float opnd2) {
	float result = 1;
	switch (op) //判断运算符
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
					opnd.push(calcu(op, pOpnd));//实施一元运算
				}
				else {
					float pOpnd2 = opnd.top(); opnd.pop();
					float pOpnd1 = opnd.top(); opnd.pop();
					opnd.push(calcu(pOpnd1, op, pOpnd2));//实施二元运算
				}
				break;
			}
			default:exit(-1);
			}//switch
	}//while
	float Result = opnd.top();//先转存计算结果,再pop
	opnd.pop();
	return Result;//弹出并返回最后的计算结果
}

int main() {
	int i;
	char test[10];
	cout << "请输入" << endl;
	
	cin >> test;
	
	cout<<evaluate(test);
	return 0;
}



