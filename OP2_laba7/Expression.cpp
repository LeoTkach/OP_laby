#include "Expression.h"
#include <iostream>

Expression::Expression(double nValue, double mValue) {
    if (nValue < 0) {
        throw gcnew System::Exception("The value of n must be non-negative");
    }
    else if (std::floor(nValue) != nValue) {
        throw gcnew System::Exception("The value of n must be a an integer");
    }
    else if (nValue > 15) {
        throw gcnew System::Exception("The value of n must not exceed 15");
    }
    else if (mValue > 1000000000 || mValue < -1000000000) {
        throw gcnew System::Exception("The value of m must be within the limits [-10^9;10^9] ");
    }
    n = nValue;
    m = mValue;
}

double Expression::calculate() {

    double factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    return (n - m) * factorial;
}
