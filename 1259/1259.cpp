#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int n) {
    // 정수를 문자열로 변환하여 팰린드롬 여부를 확인
    string str = to_string(n);
    int len = str.length();

    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        // 입력이 0이면 프로그램 종료
        if (n == 0) {
            break;
        }

        // 주어진 수가 팰린드롬인지 확인 후 출력
        if (isPalindrome(n)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
