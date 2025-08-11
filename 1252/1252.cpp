#include <iostream>
#include <algorithm> // for reverse function

using namespace std;

// �������� ���ϴ� �Լ�
string addBinary(string a, string b) {
    // �Էµ� �������� ������
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = ""; // ���� ����� ������ ���ڿ�

    int carry = 0; // �ø��� ������ ����

    // �� �������� ����
    for (int i = 0; i < max(a.length(), b.length()); i++) {
        int digitA = (i < a.length()) ? (a[i] - '0') : 0;
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;

        int sum = digitA + digitB + carry;
        result += (sum % 2) + '0'; // ���� �ڸ��� �� ����
        carry = sum / 2; // �ø� ����
    }

    // ���������� ���� �ø��� �ִ� ��� ó��
    if (carry > 0) {
        result += carry + '0';
    }

    // ����� �ٽ� ����� ��ȯ
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    // �� ���� �������� �Է¹���
    string binary1, binary2;
    cin >> binary1 >> binary2;

    // �������� ���ϰ� ����� ���
    string result = addBinary(binary1, binary2);
    cout << result << endl;

    return 0;
}