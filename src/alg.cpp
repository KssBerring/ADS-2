// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return value * pown(value, n - 1);
    }
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    double r = 0;
    r = pown(x, n)/fact(n);
    return r;
}

double expn(double x, uint16_t count) {
    double result = 1.0;
    for (uint16_t i = 1; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = x;
    for (uint64_t i = 2; i <= count; i++) {
        result += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    for (uint64_t i = 2; i <= count; i++) {
        res += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 2);
    }
    return res;
}
