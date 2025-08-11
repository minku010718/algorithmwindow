#include <iostream>

using namespace std;

// �Լ� ����
int findGCD(int a, int b);
int findLCM(int a, int b);

int main() {
    // �� ���� �ڿ��� �Է� �ޱ�
    int num1, num2;
    cin >> num1 >> num2;

    // �ִ� ������� �ּ� ����� ���
    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);

    // ��� ���
    cout << gcd << endl;
    cout << lcm << endl;

    return 0;
}

// �ִ� ����� ��� �Լ�
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// �ּ� ����� ��� �Լ�
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}
