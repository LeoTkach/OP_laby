#pragma once
#include <iostream>

ref class Expression {
private:
    double n;
    double m;

public:
    Expression(double nValue, double mValue);
    double calculate();
};