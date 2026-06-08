#include "continuedfraction.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    uint64_t A, B;
    int64_t D;

    cout << "Введите A: " << endl << ">>> ";
    cin >> A;

    cout << "Введите B: " << endl << ">>> ";
    cin >> B;

    cout << "Введите D: " << endl << ">>> ";
    cin >> D;

    cout << "\nУравнение: " << A << "a + " << B << "b = " << D << "\n\n";

    uint64_t g = gcd(A, B);
    cout << "НОД(" << A << ", " << B << ") = " << g << "\n";

    cout << "\nЦепная дробь:\n";
    vector<uint64_t> q = continuedFraction(A / g, B / g);

    cout << A / g << "/" << B / g << " = [";
    for (int i = 0; i < (int)q.size(); i++) {
        if (i == 0) cout << q[i];
        else if (i == 1) cout << "; " << q[i];
        else cout << ", " << q[i];
    }
    cout << "]\n";

    solveEquation(A, B, D);

    return 0;
}