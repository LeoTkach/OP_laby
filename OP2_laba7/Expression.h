#pragma once
#include <iostream>
#include <cmath>

ref class Expression {
private:
    double n;
    double m;

public:
    Expression(double nValue, double mValue);
    double calculate();
};