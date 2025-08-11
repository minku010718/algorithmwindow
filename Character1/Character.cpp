#include <iostream>
using namespace std;

int main() {
    int N, max = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int dice1, dice2, dice3;
        cin >> dice1 >> dice2 >> dice3;

        int ret;
        if (dice1 == dice2) {
            if (dice1 == dice3) ret = 10000 + dice1 * 1000;
            else ret = 1000 + dice1 * 100;
        }
        else {
            if (dice2 == dice3) ret = 1000 + dice2 * 100;
            else if (dice1 == dice3) ret = 1000 + dice1 * 100;
            else {
                if ((dice1 > dice2) && (dice1 > dice3)) ret = dice1 * 100;
                else if ((dice2 > dice1) && (dice2 > dice3)) ret = dice2 * 100;
                else ret = dice3 * 100;
            }
        }

        if (max < ret) max = ret;
    }

    cout << max;

    return 0;
}