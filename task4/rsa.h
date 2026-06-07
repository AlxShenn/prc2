#ifndef RSA_H
#define RSA_H
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <locale>

long long gcd(uint64_t a, uint64_t b);
uint64_t modBinary(uint64_t base, uint64_t power, uint64_t N);
uint64_t inverseEgcd(uint64_t c, uint64_t m);
std::vector<uint64_t> encryption(std::string text, uint64_t d, uint64_t N);
std::string decryption(std::vector<uint64_t> text, uint64_t c, uint64_t N);

#endif