#include"../../Vector/Vector/Vector.h"
#include"../../Vector/Vector/Complex.h"
#include<iostream>
#include<Vector>
#include<Algorithm>
#include<time.h>
#include <Windows.h>
using namespace std;

int main()
{
	Complex V1[10];
	cout << "�����������" << endl;
	for (int i = 0; i < 10; i++) {
		V1[i].read_Real(rand() % 20 + 10);
		V1[i].read_Imaginary(rand() % 20 + 10);
		V1[i].read_modulus();
		//�������
	}
	cout << endl;
	Vector<Complex> V2(V1, 10);
	for (int i = 0; i < 10; i++)
	{
		V2._elem[i].display();//��ʾ
	}
	cout << endl;
	cout << "��������" << endl;
	//�������Ҳ���
	V2.unsort(0, 10); 
	for (int i = 0; i < 10; i++)
	{
		V2._elem[i].display();//��ʾ���
	}
	cout << endl;
	//���в��Ҳ���
	int temp;
	temp = V2.find0(V1[0]);
	cout << "���Һ����ԭ����һ��Ԫ�ص�λ��Ϊ" << temp+1 << endl;
	//���в������
	Vector<Complex> V3(V1, 1);
	V3[0].read_Real(rand() % 200 / 10);
	V3[0].read_Imaginary(rand() % 200/ 10);
	V2.insert(5, V3[0]);
	cout << endl << "���м����һ������" << endl;
	for (int i = 0; i < 10; i++) 
	{
		V2._elem[i].display();
	}
	cout << endl;
	//����ɾ������
	V2.remove(0);
	cout << "ɾ����һ��Ԫ��" << endl;
	for (int i = 0; i < 10; i++) 
	{
		V2._elem[i].display();
	}
	cout << endl;
	//����Ψһ������
	int j=V2.deduplicate();
	cout << endl << "ɾ���ظ�Ԫ�أ�" << j << "��" << endl << "Ψһ����ĸ�������:" << endl;
	for (int i = 0; i < 10 - j; i++) {
		V2[i].display();
	}//���ɾ���ظ�Ԫ�غ�ĸ�������
	cout << endl;
	cout << endl;
	


	cout << "��ʼ��ʱ����" << endl;
	cout << "�����Һ������V2�����������" << endl;
	srand(time(0));//�������������ʱ����أ�ȷ����������ȫ����ĸ���
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.mergeSort(0, 10);//����ʱ�鲢����
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.bubbleSort(0, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	cout << "����������" << endl;
	for (int i = 0; i < 5; i++) {
		swap(V2[i], V2[9 - i]);
	}//��������������
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.mergeSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.bubbleSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;
	
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.mergeSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	V2.bubbleSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;
	cout<< endl;

	cout << "�������" << endl;
	double V4[10];
	for (int i = 0; i < 10; i++) {
		V4[i] = V2._elem[i].display2();
	}
	Vector<Complex> V5(V1, 10);
	for (int i = 0; i < 10; i++) {
		V5[i].read_Real(V4[i]);
		V5[i].read_Imaginary(0);
		V5[i].read_modulus();
	}
	int sum = V5.find2(10, 30, 0, 10);
	cout << "����Ϊ��" << sum << endl;
	for (int i = 0; i < sum; i++)
		V2._elem[i].display();

}
