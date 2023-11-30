#include <iostream>
#include <cmath>

// Задані функції
double fn1(double x) {
    return 9.2 * cos(2 * x) - fabs(sin(x) / 1.1);
}

double fn2(double x) {
    return 12.4 * sin(fabs(x / 2.1)) - 8.3 * cos(1.2 * x);
}

double fn3(double x) {
    return fabs(cos(x) / 2.7) + 9.1 * sin(1.2 * x + 1);
}

double fn4(double x) {
    return fabs(sin(x) / 3.12 + cos(x));
}

double fn5(double x) {
    return cos(fabs(2 * x)) / 1.12 - cos(3 * x - 2) + 6.15;
}

double fn6(double x) {
    return sin(x) * pow(cos(x), 2) * sin(x + 1.4) / 0.85 + 7.14;
}

int main() {
    int i = 6; // Номер варіанту
    double a = 0, b = 1; // Ініціалізація a та b

    // Обчислення a
    for (int k = i; k <= i + 5; ++k) {
        a += fn1(k) + fn2(k) + fn3(k) + fn4(k) + fn5(k) + fn6(k);
    }

    // Обчислення b
    for (int k = i; k <= i + 7; ++k) {
        b *= fn2(k);
    }

    // Виведення значень a та b
    std::cout << "i = " << i << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // Обчислення та виведення значення z за 6-м варіантом
    double z6 = sin(a) + b;
    std::cout << "z = " << z6 << std::endl;

    return 0;
}
