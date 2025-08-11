#include <iostream>

using namespace std;

// 함수 선언
int findGCD(int a, int b);
int findLCM(int a, int b);

int main() {
    // 두 개의 자연수 입력 받기
    int num1, num2;
    cin >> num1 >> num2;

    // 최대 공약수와 최소 공배수 계산
    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);

    // 결과 출력
    cout << gcd << endl;
    cout << lcm << endl;

    return 0;
}

// 최대 공약수 계산 함수
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소 공배수 계산 함수
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}
