#include <iostream>
#include "Stack1.h"
#include"../../Vector/Vector/Vector.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n;
    cout << "������߶���������:";
    cin >> n;
    int heights[10];
    cout << "����߶�: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    calculate_largest_rectangle_area(heights, n);
    srand(time(NULL));  // ���������

    for (int i = 0; i < 10; ++i) {
        int arr[5] = { 0 };
        cout << "Array " << i + 1 << ": ";
        for (int j = 0; j < 5; ++j) {
            int num = rand() % 106;  // ����0~105֮����������
            while (arr[num % 5] != 0) {  // ȷ�����ɵ������ظ�
                num = rand() % 106;
            }
            arr[num % 5] = num;
            cout << num << " ";
        }
        calculate_largest_rectangle_area(arr, 5);
        cout << endl;
    }

    return 0;
}



