#include <iostream>
#include <algorithm> // for reverse function

using namespace std;

// 이진수를 더하는 함수
string addBinary(string a, string b) {
    // 입력된 이진수를 뒤집음
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = ""; // 덧셈 결과를 저장할 문자열

    int carry = 0; // 올림을 저장할 변수

    // 두 이진수를 더함
    for (int i = 0; i < max(a.length(), b.length()); i++) {
        int digitA = (i < a.length()) ? (a[i] - '0') : 0;
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;

        int sum = digitA + digitB + carry;
        result += (sum % 2) + '0'; // 현재 자리의 값 저장
        carry = sum / 2; // 올림 갱신
    }

    // 마지막으로 남은 올림이 있는 경우 처리
    if (carry > 0) {
        result += carry + '0';
    }

    // 결과를 다시 뒤집어서 반환
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    // 두 개의 이진수를 입력받음
    string binary1, binary2;
    cin >> binary1 >> binary2;

    // 이진수를 더하고 결과를 출력
    string result = addBinary(binary1, binary2);
    cout << result << endl;

    return 0;
}