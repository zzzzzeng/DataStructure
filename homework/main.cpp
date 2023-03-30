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
	cout << "生成随机向量" << endl;
	for (int i = 0; i < 10; i++) {
		V1[i].read_Real(rand() % 20 + 10);
		V1[i].read_Imaginary(rand() % 20 + 10);
		V1[i].read_modulus();
		//随机向量
	}
	cout << endl;
	Vector<Complex> V2(V1, 10);
	for (int i = 0; i < 10; i++)
	{
		V2._elem[i].display();//显示
	}
	cout << endl;
	cout << "进行置乱" << endl;
	//进行置乱操作
	V2.unsort(0, 10); 
	for (int i = 0; i < 10; i++)
	{
		V2._elem[i].display();//显示结果
	}
	cout << endl;
	//进行查找操作
	int temp;
	temp = V2.find0(V1[0]);
	cout << "置乱后查找原来第一个元素的位置为" << temp+1 << endl;
	//进行插入操作
	Vector<Complex> V3(V1, 1);
	V3[0].read_Real(rand() % 200 / 10);
	V3[0].read_Imaginary(rand() % 200/ 10);
	V2.insert(5, V3[0]);
	cout << endl << "在中间插入一个向量" << endl;
	for (int i = 0; i < 10; i++) 
	{
		V2._elem[i].display();
	}
	cout << endl;
	//进行删除操作
	V2.remove(0);
	cout << "删除第一个元素" << endl;
	for (int i = 0; i < 10; i++) 
	{
		V2._elem[i].display();
	}
	cout << endl;
	//进行唯一化操作
	int j=V2.deduplicate();
	cout << endl << "删除重复元素：" << j << "个" << endl << "唯一化后的复数向量:" << endl;
	for (int i = 0; i < 10 - j; i++) {
		V2[i].display();
	}//输出删除重复元素后的复数向量
	cout << endl;
	cout << endl;
	


	cout << "开始计时操作" << endl;
	cout << "对置乱后的向量V2进行排序操作" << endl;
	srand(time(0));//设置随机种子与时间相关，确保能生成完全随机的复数
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.mergeSort(0, 10);//乱序时归并排序
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "乱序时归并排序运行时间：" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.bubbleSort(0, 10);//乱序时起泡排序
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "乱序时起泡排序运行时间：" << time * 1000 << "ms" << endl;

	cout << "将向量逆序" << endl;
	for (int i = 0; i < 5; i++) {
		swap(V2[i], V2[9 - i]);
	}//将复数向量逆序
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.mergeSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "逆序时归并排序运行时间：" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.bubbleSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "逆序时起泡排序运行时间：" << time * 1000 << "ms" << endl;
	
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.mergeSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "顺序时归并排序运行时间：" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	V2.bubbleSort(0, 10);
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "顺序时起泡排序运行时间：" << time * 1000 << "ms" << endl;
	cout<< endl;

	cout << "区间查找" << endl;
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
	cout << "个数为：" << sum << endl;
	for (int i = 0; i < sum; i++)
		V2._elem[i].display();

}
