#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();
    void push(int item);
    int pop();
    int peek();
    bool is_empty();
    bool is_full();
    int size();
};

#endif
Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int item) {
    if (is_full()) {
        cout << "Stack overflow\n";
        return;
    }
    top++;
    arr[top] = item;
}

int Stack::pop() {
    if (is_empty()) {
        cout << "Stack underflow\n";
        return -1;
    }
    int item = arr[top];
    top--;
    return item;
}

int Stack::peek() {
    if (is_empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

bool Stack::is_empty() {
    return top == -1;
}

bool Stack::is_full() {
    return top == capacity - 1;
}

int Stack::size() {
    return top + 1;
}
void calculate_largest_rectangle_area(int heights[], int n) {
    int max_area = 0;
    Stack stack(n);
    int i = 0;
    while (i < n) {
        if (stack.is_empty() || heights[i] >= heights[stack.peek()]) {
            stack.push(i);
            i++;
        }
        else {
            int height = heights[stack.pop()];
            int width = stack.is_empty() ? i : i - stack.peek() - 1;
            max_area = max(max_area, height * width);
        }
    }
    while (!stack.is_empty()) {
        int height = heights[stack.pop()];
        int width = stack.is_empty() ? i : n - stack.peek() - 1;
        max_area = max(max_area, height * width);
    }
    cout << "矩形最大面积: " << max_area << endl;
}
