#include "types.hpp"
#include <limits>

int DivideInts(int a, int b) {
    return a / b;
}

double DivideAsDouble(int a, int b) {
    return 1.0 * a / b;
}

bool FitsInInt(long long value) {
    return (value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min());
}

long long SumAsLongLong(int a, int b) {
    long long a1 = a;
    long long b1 = b;
    return a1 + b1;
}
    
