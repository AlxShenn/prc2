#include "egcd.h"

using namespace std;

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
        cout << "Ошибка: c и m должны быть взаимно простыми!" << endl;
    }

    uint64_t d = (u3 > 0)? u3: u3 + m0;
}