#include <iostream>
#include <cmath>
# pragma once
using namespace std;
//������
class Complex {
public:  //���캯��
    inline Complex(double real = 0 , double imag = 0) : m_real(real), m_imag(imag) {}
public:  //���������
    //��ȫ�ֺ�������ʽ����
    friend bool operator> (const Complex& c1, const Complex& c2);
    friend bool operator< (const Complex& c1, const Complex& c2);
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);
    void display();
    double read_Real(double r);
    double read_Imaginary(double i);
    double read_modulus();
    double display2();
public:  //��Ա����
    double real() const { return m_real; }
    double imag() const { return m_imag; }
    double modulus() const { return m_modulus; }
    double m_real;  //ʵ��
    double m_imag;  //�鲿
    double m_modulus;  //ģ�� 
};
//����==�����
bool operator==(const Complex& c1, const Complex& c2) {
    if (c1.m_real == c2.m_real && c1.m_imag == c2.m_imag) {
        return true;
    }
    else {
        return false;
    }
}
//����> <����� 
bool operator>(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus > c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>(const Complex& c1, double m) {
    if (c1.m_modulus > m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus < c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<(const Complex& c1, double m) {
    if (c1.m_modulus < m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus <= c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(const Complex& c1, double m) {
    if (c1.m_modulus <= m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>=(const Complex& c1, double m) {
    if (c1.m_modulus >= m * m) {
        return true;
    }
    else {
        return false;
    }
}
//����!=�����
bool operator!=(const Complex& c1, const Complex& c2) {
    if (c1.m_real != c2.m_real || c1.m_imag != c2.m_imag) {
        return true;
    }
    else {
        return false;
    }
}
//��ʾ���� 
void Complex::display() {
    if (m_real != 0) {
        if (m_imag > 0) {
            cout << m_real << "+" << m_imag << "i" << " ";
        }
        else cout << m_real << m_imag << "i" << " ";
    }
    if (m_imag == 0)
        cout << m_imag << "i" << " ";
}
double Complex::display2() {
    double x = m_modulus;
    return x;
}
//ʵ�� �鲿 ģ 
double Complex::read_Real(double r) {
    m_real = r;
    return m_real;
}
double Complex::read_Imaginary(double i) {
    m_imag = i;
    return m_imag;
}
double Complex::read_modulus() {
    m_modulus = m_imag * m_imag + m_real * m_real;
    return m_modulus;
}

