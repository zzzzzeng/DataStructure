#include <iostream>
#include "Stack1.h"
#include"../../Vector/Vector/Vector.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n;
    cout << "请输入高度数组数量:";
    cin >> n;
    int heights[10];
    cout << "输入高度: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    calculate_largest_rectangle_area(heights, n);
    srand(time(NULL));  // 随机数种子

    for (int i = 0; i < 10; ++i) {
        int arr[5] = { 0 };
        cout << "Array " << i + 1 << ": ";
        for (int j = 0; j < 5; ++j) {
            int num = rand() % 106;  // 生成0~105之间的随机整数
            while (arr[num % 5] != 0) {  // 确保生成的数不重复
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



