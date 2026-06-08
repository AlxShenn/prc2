#include "egcd.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    uint64_t c, m;
    cout << "Расширенный алгоритм Евклида для c * d = 1 mod m" << endl;
    cout << "Введите c: " << endl; cout << ">>> ";
    cin >> c;
    cout << "Введите m: " << endl; cout << ">>> ";
    cin >> m;

    uint64_t d = egcd(c, m);
    cout << "d = " << d << endl;
    cout << c << " * " << d << " = " << c * d << " = " << 
        ((c *d ) / m) * m << " + 1" <<" = 1 mod " << m << endl;


    uint64_t cA, mA;
    cout << "Вычисление c^(-1) mod m" << endl;
    cout << "Введите c: ";
    cin >> cA;
    cout << "Введите m: ";
    cin >> mA;
    uint64_t dA = inverseEgcd(cA, mA);
    if (!dA) return 0;
    cout << "d = " << dA << endl;
    cout << cA << "^(-1) mod " << mA << " = " << dA << endl;
    return 0;
}
