#include "continuedfraction.h"

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b) { 
    while (b) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<uint64_t> continuedFraction(uint64_t A, uint64_t B) {
    vector<uint64_t> q;

    while (B != 0) {
        q.push_back(A / B);

        uint64_t temp = B;
        B = A % B;
        A = temp;
    }

    return q;
}

void solveEquation(uint64_t A, uint64_t B, int64_t D) {
    uint64_t g = gcd(A, B);

    cout << "НОД(" << A << ", " << B << ") = " << g << "\n";

    if (D % (int64_t)g != 0) {
        cout << "Решений в целых числах нет!\n";
        return;
    }

    uint64_t A1 = A / g;
    uint64_t B1 = B / g;
    int64_t D1 = D / (int64_t)g;

    vector<uint64_t> q = continuedFraction(A1, B1);

    cout << "Цепная дробь для " << A1 << "/" << B1 << ": [";
    for (int i = 0; i < (int)q.size(); i++) {
        if (i == 0) cout << q[i];
        else if (i == 1) cout << "; " << q[i];
        else cout << ", " << q[i];
    }
    cout << "]\n";

    // подходящие дроби P_i / Q_i
    uint64_t Pm2 = 0, Pm1 = 1;
    uint64_t Qm2 = 1, Qm1 = 0;

    vector<uint64_t> P, Q;

    for (int i = 0; i < (int)q.size(); i++) {
        uint64_t Pi = q[i] * Pm1 + Pm2;
        uint64_t Qi = q[i] * Qm1 + Qm2;

        P.push_back(Pi);
        Q.push_back(Qi);

        Pm2 = Pm1;
        Pm1 = Pi;
        Qm2 = Qm1;
        Qm1 = Qi;
    }

    int n = (int)q.size() - 1;

    int64_t a0, b0;

    if (n == 0) {
        // если дробь состоит из одного элемента, то B1 = 1
        a0 = 0;
        b0 = D1;
    } else {
        uint64_t Pprev = P[n - 1];
        uint64_t Qprev = Q[n - 1];

        // A1 * Q_{n-1} - B1 * P_{n-1} = (-1)^(n-1)
        int64_t sign = (n % 2 == 1) ? 1 : -1;

        a0 = sign * (int64_t)Qprev * D1;
        b0 = -sign * (int64_t)Pprev * D1;
    }

    cout << "Частное решение:\n";
    cout << "a0 = " << a0 << "\n";
    cout << "b0 = " << b0 << "\n";

    cout << "Проверка: " << A << " * " << a0 << " + " << B << " * " << b0;
    cout << " = " << (int64_t)A * a0 + (int64_t)B * b0 << "\n";
}