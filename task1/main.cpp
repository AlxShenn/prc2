#include "axmodp.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    uint64_t base, power, modulo;

    cout << "Введите основание base:" << endl << ">>> ";
    cin >> base;
    cout << "Введите степень power:" << endl << ">>> ";
    cin >> power;
    cout << "Введите модуль modulo:" << endl << ">>> ";
    cin >> modulo;

    if (conditions(base, modulo) == false) {
        cout << "Ошибка: основание или модуль некорректны!";
        return 0;
    }
    cout << "Ферма: " << base << "^" << power << " mod" << modulo << 
        " = " << modFermat(base, power, modulo) << endl;
    cout << "Бинарный алгоритм: " << base << "^" << power << " mod" << modulo << 
        " = " << modBinary(base, power, modulo) << endl;

}
