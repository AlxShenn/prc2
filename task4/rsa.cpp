#include "rsa.h"
#include <iomanip>

using namespace std;

long long gcd(uint64_t a, uint64_t b) { 
    while (b) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

uint64_t modBinary(uint64_t base, uint64_t power, uint64_t N) {
    base %= N;
    uint64_t res = 1;

    while (power > 0) {
        if (power & 1) {
            res = (res * base) % N;
        }
        power >>= 1;
        base = (base * base) % N;

    }
    return res;
}

uint64_t inverseEgcd(uint64_t c, uint64_t m) {
    int64_t u1 = 0, u2 = 1, u3;
    uint64_t m0 = m;
    c = c % m;
    uint64_t r0;
    uint64_t q = c / m;
    uint64_t r = c % m;

    cout << "\t" << "r" << "\t" << "u" << "\t" << "q" << endl;
    cout << "\t" << m << "\t" << u1 << "\t" << "-" << endl;
    cout << "\t" << c << "\t" << u2 << "\t" << "-" << endl;

    while (r > 0) {
        r0 = r;
        u3 = u1 - u2 * q;
        cout << "\t" << r << "\t" << u3 << "\t" << q << endl;

        m = c; c = r;
        u1 = u2; u2 = u3;
        q = m / c;
        r = m % c;
    }

    if (r0 != 1) {
        cout << "Ошибка: Публичный ключ d и функция Эйлера phi(N) должны быть взаимно простыми!" << endl;
    }

    uint64_t d = (u3 > 0)? (uint64_t)u3: (uint64_t)(u3 + m0);
    return d;
}

vector<uint64_t> encryption(string text, uint64_t d, uint64_t N) {
    vector<uint64_t> res;
    cout << "Символ" << "\t" << "Номер" << "\t" << "Результат шифрования" << endl;

    for (int i = 0; i < text.size(); i++) {
        uint64_t encryptedNumber = (unsigned char)text[i];
        uint64_t encryptedChar = modBinary(encryptedNumber, d, N);

        cout << text[i] << "\t" << encryptedNumber << "\t" << encryptedChar << endl;
        res.push_back(encryptedChar);
    }

    return res;
}

string decryption(vector<uint64_t> text, uint64_t c, uint64_t N) {
    string res;

    for (int i = 0; i < text.size(); i++) {
        uint64_t decryptedNumber = modBinary(text[i], c, N);
        char decryptedChar = (char)(unsigned char)decryptedNumber;

        cout << text[i] << "\t" << decryptedNumber << "\t" << decryptedChar << endl;
        res.push_back(decryptedChar);
    }

    return res;
}