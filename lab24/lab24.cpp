#include <iostream>
#include <cmath>

using namespace std;

class Rational {
public:
    Rational() {
        // Реалізуйте конструктор за замовчуванням
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
        // Реалізуйте конструктор
        int gcd_value = GreatestCommonDivisor(abs(numerator), abs(denominator));
        numerator_ = numerator / gcd_value;
        denominator_ = denominator / gcd_value;
        if (denominator < 0) {
            numerator_ = -numerator_;
            denominator_ = abs(denominator_);
        }
        else if (numerator == 0) {
            denominator_ = 1;
        }
    }

    int Numerator() const {
        // Реалізуйте цей метод
        return numerator_;
    }

    int Denominator() const {
        // Реалізуйте цей метод
        return denominator_;
    }

private:
    // Додайте поля
    int numerator_;
    int denominator_;

    int GreatestCommonDivisor(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return GreatestCommonDivisor(b, a % b);
        }
    }
};

int main() {
    const Rational r1(3, 10);
    if (r1.Numerator() != 3 || r1.Denominator() != 10) {
        cout << "Rational(3, 10) != 3/10" << endl;
        return 1;
    }

    const Rational r2(8, 12);
    if (r2.Numerator() != 2 || r2.Denominator() != 3) {
        cout << "Rational(8, 12) != 2/3" << endl;
        return 2;
    }

    const Rational r3(-4, 6);
    if (r3.Numerator() != -2 || r3.Denominator() != 3) {
        cout << "Rational(-4, 6) != -2/3" << endl;
        return 3;
    }

    const Rational r4(4, -6);
    if (r4.Numerator() != -2 || r4.Denominator() != 3) {
        cout << "Rational(4, -6) != -2/3" << endl;
        return 4;
    }

    const Rational r5(0, 15);
    if (r5.Numerator() != 0 || r5.Denominator() != 1) {
        cout << "Rational(0, 15) != 0/1" << endl;
        return 5;
    }

    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
        cout << "Rational() != 0/1" << endl;
        return 6;
    }

    cout << "OK" << endl;
    return 0;
}
