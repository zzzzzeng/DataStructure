#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main() {
    vector<int> arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> arr2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> arr3;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr3.push_back(rand() % 100);
    }
    cout << "起泡排序:" << endl;
    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "顺序排序后的数组: ";

    printArray(arr1);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    bubbleSort(arr2);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "逆序排序后的数组: ";

    printArray(arr2);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    bubbleSort(arr3);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "随机排序后的数组: ";

    printArray(arr3);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    cout << endl;
    vector<int> arr4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> arr5 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> arr6;

    for (int i = 0; i < 10; i++) {
        arr6.push_back(rand() % 100);
    }
    cout << "插入排序:" << endl;
    start = chrono::high_resolution_clock::now();

    insertionSort(arr4);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "顺序排序后的数组: ";

    printArray(arr4);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    insertionSort(arr5);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "逆序排序后的数组: ";

    printArray(arr5);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    insertionSort(arr6);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "随机排序后的数组: ";

    printArray(arr6);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    cout << endl;

    vector<int> arr7 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> arr8 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> arr9;
    for (int i = 0; i < 10; i++) {
        arr9.push_back(rand() % 100);
    }
    cout << "选择排序:" << endl;
    start = chrono::high_resolution_clock::now();

    selectionSort(arr7);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "顺序排序后的数组: ";

    printArray(arr7);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    selectionSort(arr8);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "逆序排序后的数组: ";

    printArray(arr8);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    selectionSort(arr9);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "随机排序后的数组: ";

    printArray(arr9);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    cout << endl;
    vector<int> arr10 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> arr11 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> arr12;
    for (int i = 0; i < 10; i++) {
        arr12.push_back(rand() % 100);
    }
    cout << "归并排序:" << endl;
    start = chrono::high_resolution_clock::now();

    mergeSort(arr10, 0, arr10.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "顺序排序后的数组: ";

    printArray(arr10);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    mergeSort(arr11, 0, arr11.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "逆序排序后的数组: ";

    printArray(arr11);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    mergeSort(arr12, 0, arr12.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "随机排序后的数组: ";

    printArray(arr12);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    cout << endl;

    vector<int> arr13 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> arr14 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> arr15;
    for (int i = 0; i < 10; i++) {
        arr15.push_back(rand() % 100);
    }
    cout << "快速排序:" << endl;
    start = chrono::high_resolution_clock::now();

    quickSort(arr13, 0, arr13.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "顺序排序后的数组: ";

    printArray(arr13);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    quickSort(arr14, 0, arr14.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "逆序排序后的数组: ";

    printArray(arr14);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    start = chrono::high_resolution_clock::now();

    quickSort(arr15, 0, arr15.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "随机排序后的数组: ";

    printArray(arr15);
    cout << "所用时间: " << duration.count() << " microseconds" << endl;
    return 0;
}
