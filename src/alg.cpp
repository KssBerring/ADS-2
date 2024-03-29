// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
 if (n == 0) {
        return 1;
    } 
 else {
        return value * pown(value, n - 1);
    }
}

uint64_t fact(uint16_t n) {
 if (n == 0) {
        return 1;
    } 
 else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1.0; 
    for (uint16_t n = 1; n <= count; ++n) {
        result += calcItem(x, n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
 double result = 0;
int sign = 1;
for (uint16_t i = 1; i <= count*2; ++i) {
    if ((i / 2) != 0) {
        result += sign * calcItem(x, i);
        sign *= -1;
    }
}
return result;
}

double cosn(double x, uint16_t count) {
 double result = 0;
int sign = 1;
for (uint16_t i = 0; i <= count*2; ++i) {
    if ((i / 2) == 0) {
        result += sign * calcItem(x, i);
        sign *= -1;
    }
}
return result;
}
