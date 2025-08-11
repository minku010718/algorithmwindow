#include <iostream>

int main() {
    int A, B, C, D;
    int P, M, N;

    std::cin >> A >> B >> C >> D;
    std::cin >> P >> M >> N;

    int dog1 = ((P - 1) % (A + B) < A);
    int dog2 = ((M - 1) % (C + D) < C);
    int dog3 = ((N - 1) % (A + B) < A);

    std::cout << dog1 << std::endl;
    std::cout << dog2 << std::endl;
    std::cout << dog3 << std::endl;

    return 0;
}
