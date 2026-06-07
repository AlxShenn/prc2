#include "rsa.h"

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
    
    uint64_t p, q;

    cout << "Введите простые числа p и q: " << endl << ">>> ";
    cin >> p >> q;
    uint64_t N = p * q;
    cout << "N = p * q = " << N << endl;

    uint64_t phi = (p - 1) * (q - 1);
    cout << "Вычисление функции Эйлера для N: phi(N) = (p - 1) * (q - 1) = " << phi << endl;
    cout << "Введите публичный ключ d: " << endl << ">>> ";
    uint64_t d;
    cin >> d;

    if (gcd(d, phi) != 1) {
        cout << "Ошибка: публичный ключ d и фунукция Эйлера phi(N) должны быть взаимно простыми!" << endl;
        return 0;
    }

    cout << "Вычисление закрытого ключа: d^(-1) mod phi = cB" << endl;
    uint64_t c = inverseEgcd(d, phi);
    cout << d << "^(-1) mod " << phi << " = " << c << endl;

    cout << "\nОткрытый ключ (d, N): (" << d << ", " << N << ")" << endl;
    cout << "Закрытый ключ (cB, phi): (" << c << ", " << phi << ")" << endl;

    string text;
    cout << "Введите текст для шифрования: " << endl << ">>> ";
    getline(cin, text);

    std::vector<uint64_t> encrypted = encryption(text, d, N);

    cout << "\nЗашифрованный текст:\n";
    for (const auto& ch : encrypted) {
        cout << ch << " ";
    }

    string decrypted = decryption(encrypted, c, N);

    cout << "\nРасшифрованный текст:\n";
    cout << decrypted << endl;

    return 0;
}