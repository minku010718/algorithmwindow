#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    if (n == 1)
    {
        cout << n << endl;
        cout << "0" << endl;
        return 0;
    }

    if (n % 2 == 1)
    {
        n++;
    }

    if (n)
    {
        cout << n / 2 << endl;
        cout << "1" << endl;
    }
    else
    {
        cout << "4" << endl;
    }

    return 0;
}
