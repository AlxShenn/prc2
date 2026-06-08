#ifndef CONTINUEDFRACTION_H
#define CONTINUEDFRACTION_H
#include <iostream>
#include <vector>
#include <locale>
#include <cstdint>

uint64_t gcd(uint64_t a, uint64_t b);
std::vector<uint64_t> continuedFraction(uint64_t A, uint64_t B);
void solveEquation(uint64_t A, uint64_t B, int64_t D);

#endif