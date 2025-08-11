#include "Exp.h"

Exp::Exp() {
    base = 1;
    exp = 1;
}

Exp::Exp(int b) {
    base = b;
    exp = 1;
}

Exp::Exp(int b, int e) {
    base = b;
    exp = e;
}

int Exp::getValue() {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int Exp::getBase() {
    return base;
}

int Exp::getExp() {
    return exp;
}

bool Exp::equals(Exp b) {
    return this->getValue() == b.getValue();
}
