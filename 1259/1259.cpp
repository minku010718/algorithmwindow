#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int n) {
    // ������ ���ڿ��� ��ȯ�Ͽ� �Ӹ���� ���θ� Ȯ��
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

        // �Է��� 0�̸� ���α׷� ����
        if (n == 0) {
            break;
        }

        // �־��� ���� �Ӹ�������� Ȯ�� �� ���
        if (isPalindrome(n)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
