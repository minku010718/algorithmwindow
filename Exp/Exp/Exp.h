#ifndef EXP_H
#define EXP_H

class Exp {
private:
    int base;
    int exp;

public:
    Exp(); // default constructor
    Exp(int b); // constructor with one argument
    Exp(int b, int e); // constructor with two arguments

    int getValue(); // returns base^exp as an integer
    int getBase(); // returns base value
    int getExp(); // returns exp value
    bool equals(Exp b); // returns true if this object and object b have the same value
};

#endif
