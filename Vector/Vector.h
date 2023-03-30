#include<stdlib.h>
#include<iostream>
#include<cmath>

typedef int Rank; //�� 
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ���� 
using namespace std;

template <typename T>  class Vector { //����ģ���� 
public:
	Rank _size; int _capacity; T* _elem; //��ģ ���� ������ 
	void copyFrom(T const* A, Rank lo, Rank hi); // ������������A[lo ,hi) 
	void expand(); //�ռ䲻��ʱ���� 
	void shrink(); //װ�����ӹ�Сʱѹ�� 
	bool bubble(Rank lo, Rank hi); //ɨ�轻�� 
	bool bubble(Rank n, Rank lo, Rank hi);
	void bubbleSort(Rank n, Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi); //ð�������㷨 
	Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ�� 
	void selectionSort(Rank lo, Rank hi); //ѡ�������㷨 
	void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨 
	void mergeSort(Rank lo, Rank hi); //�鲢�����㷨 
	void uniquify(T);
	int find1(int min, int max, Rank lo, Rank hi);
	int find2(int min, int max, Rank lo, Rank hi);
public:
	//���캯�� 
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�صĳ�ʼֵΪv 
	{
		_elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v);
	} //s<=c 
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴�� 
	Vector(T const* A, Rank lo, Rank hi) { copyForm(A, 0, hi); } //���� 
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); } //�������帴�� 
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //���� 
	//��������
	~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�
	//ֻ�����ʽӿ�	Rank size() const { return _size; } //��ģ 
	bool empty() const { return !_size; } //�п� 
	int disordered() const; //�ж������Ƿ������� 
	Rank find0(T const& e) const { return find0(e, 0, _size); } //��������������� 
	Rank find0(T const& e, Rank lo, Rank hi) const; //��������������� 
	Rank search(T const& e) const //��������������� 
	{
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	Rank search(T const& e, Rank lo, Rank hi) const;  //��������������� 
	//��д���ʽӿ�
	T& operator[] (Rank r) const; //�����±������������������������ʽ���ø�Ԫ�� 
	Vector<T>& operator= (Vector<T> const&); //���ظ�ֵ���������Ա�ֱ�ӿ�¡���� 
	T remove(Rank r); //ɾ����Ϊr��Ԫ�� 
	int remove(Rank lo, Rank hi); //ɾ����������[lo , hi)֮�ڵ�Ԫ�� 
	Rank insert(Rank r, T const& e); //����Ԫ�� 
	Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز��� 
	void sort(Rank lo, Rank hi); //��[lo ,hi)���� 
	void sort() { sort(0, _size); } //�������� 
	void unsort(Rank lo, Rank hi); //��[lo, hi)���� 
	void unsort() { unsort(0, _size); } //�������� 
	int deduplicate(); //����ȥ�� 
	int uniquify(); //����ȥ�� 


	//����
	void traverse(void (*) (T&)); //����(ʹ�ú���ָ�룬ֻ����ֲ����޸�) 
	template <typename VST> void traverse(VST&); //����(ʹ�ú������󣬿�ȫ���Ըı�) 
};//Vector 

template <typename T> //Ԫ������ 
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) { //����������[lo, hi)Ϊ������������ 
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0; //����ռ䣬��ģ���� 
	while (lo < hi) //A[lo, hi)�ڵ�Ԫ����һ 
		_elem[_size++] = A[lo++]; //������_elem[0, hi-lo) 
}

template <typename T> Vector<T>& Vector<T>::operator= (Vector<T> const& V) { //���� 
	if (_elem) delete[] _elem; //�ͷ�ԭ������ 
	copyFrom(V.elem, 0, V.size()); //���帴�� 
	return *this; //���ص�ǰ��������ã��Ա���ʽ��ֵ 
}

//���� 
template <typename T> void Vector<T>::expand() { //�����ռ䲻��ʱ���� 
	if (_size < _capacity) return; //��δ��Աʱ���������� 
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //��������С���� 
	T* oldElem = _elem; _elem = new T[_capacity <<= 1]; //�����ӱ� 
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i]; //����ԭ����������(TΪ�������ͣ��������ظ�ֵ��������= ��) 
	delete[] oldElem; //�ͷ�ԭ�пռ� 
}

//���� 
template <typename T> void Vector<T>::shrink() { // װ�����ӹ�Сʱѹ��������ռ�ռ� 
	if (_capacity < DEFAULT_CAPACITY << 1) return; //����������DEFAULT_CAPACITY����
	if (_size << 2 > _capacity) return; //��25%Ϊ��
	T* oldElem = _elem; _elem = new T[_capacity >>= 1]; //��������
	for (int i = 0; i < _size; i++) _elem[i] = oldElem[i]; //����ԭ��������
	delete[] oldElem; //�ͷ�ԭ�ռ� 
}

template <typename T> T& Vector<T>::operator[] (Rank r) const //�����±������
{
	return _elem[r];
} //assert: 0 <= r < _size

//���� 
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
	T* V = _elem + lo;
	for (Rank i = hi - lo; i > 0; i--)
		swap(V[i - 1], V[rand() % i]);
} //��[lo, hi)����

//���� 
template <typename T>
Rank Vector<T>::find0(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}

//���� 
template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand(); //�б�Ҫ������
	for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
	_elem[r] = e; _size++;
	return r; //������
}

template <typename T> int Vector<T>::remove(Rank lo, Rank hi) { //����ɾ�� 
	if (lo == hi) return 0; //����Ч�ʣ����������˻��������remove(0,0) 
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	shrink(); //�б�Ҫ������
	return hi - lo;
}

template <typename T> T Vector<T>::remove(Rank r) { //����Ԫ��ɾ��
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template <typename T> int Vector<T>::deduplicate() { //Ψһ��(��Ч��)
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		(find0(_elem[i], 0, i) < 0) ?
		i++ : remove(i);
	return oldSize - _size;
}

template <typename T> void Vector<T>::traverse(void (*visit) (T&))
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

//�ж��Ƿ������� 
template <typename T> int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++)
		if (_elem[i - 1] > _elem[i]) n++;
	return n;
}

template <typename T> //����������������� 
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	binSearch(_elem, e, lo, hi);
}

template <typename T> static Rank binsearch(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		if (e < A[mi] < e) lo = mi + 1;
		else if (A[mi] < e) lo = mi + 1;
		else return mi;
	}
	return -1;
}

template <typename T>//ð������ 
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));
}


template<typename T>
bool Vector<T>::bubble(Rank n, Rank lo, Rank hi)
{
	bool sorted = true;
	while (++lo < hi)
	{
		if (_elem[lo - 1] < _elem[lo])
		{
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);	//��������ֵ
		}
	}
	return sorted;
}


template<typename T>
void Vector<T>::bubbleSort(Rank n, Rank lo, Rank hi)	//ð������
{
	while (!bubble(n, lo, hi--));
}

template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi)
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}

template <typename T>//���������Ĺ鲢����
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	int mi = (lo + hi) / 2;
	mergeSort(lo, mi); mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T> //���������Ĺ鲢
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	//��mi Ϊ�磬���������������[lo,mi) [mi, hi)
	T* A = _elem + lo; //�ϲ��������A[0,hi-lo) = _elem[lo,hi)
	int lb = mi - lo; T* B = new T[lb];//ǰ������B[0,lb) = _elem[lo,mi)
	for (Rank i = 0; i < lb; B[i] = A[i++]);//����ǰ������,ֻ��ǰ����б�Ҫ���ƣ��б����ǵķ���
	int lc = hi - mi; T* C = _elem + mi;//ǰ������C[0,lc) = _elem[mi,hi)
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		// ��B[j]��C[k]�е�С������A��ĩβ
		if ((j < lb) && (!(k < lc) || B[j] <= C[k])) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || C[k] <= B[j])) A[i++] = C[k++];
	}
	delete[]B; //�ͷ���ʱ�ռ�B
} // �鲢��õ��������������� lo,hi

template <typename T>
int  Vector<T>::find1(int min, int max, Rank lo, Rank hi) {
	int count = 0;
	for (int i = lo; i < hi; i++) {
		if (_elem[i] > min && _elem[i] < max)
			count++;
	}
	return count;
}

template <typename T>
int  Vector<T>::find2(int min, int max, Rank lo, Rank hi) {
	int count = 0;
	for (int i = lo; i < hi; i++) {
		if (_elem[i] > min * min && _elem[i] < max * max) {
			_elem[count] = _elem[i];
			count++;
		}
	}
	return count;
}
template <typename T> int Vector<T>::uniquify() {
	Rank i = 0, j = 0;	//���Ի��조���ڡ�Ԫ�ص���
	while (++j < _size)	//��һɨ�裬ֱ��ĩԪ��
		//������ͬ�ߣ����ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
		if (_elem[i] != _elem[j]) _elem[++i] = _elem[j];
	_size = ++i; shrink();	//ֱ�ӽس�β������Ԫ��
	return j - i;		//������ģ�仯��������ɾ��Ԫ������
}				
