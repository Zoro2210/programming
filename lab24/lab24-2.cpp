#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
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
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

    bool operator==(const Rational& other) const {
        return (numerator_ == other.numerator_) && (denominator_ == other.denominator_);
    }

    Rational operator+(const Rational& other) const {
        int new_numerator = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
        int new_denominator = denominator_ * other.denominator_;
        return Rational(new_numerator, new_denominator);
    }

    Rational operator-(const Rational& other) const {
        int new_numerator = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
        int new_denominator = denominator_ * other.denominator_;
        return Rational(new_numerator, new_denominator);
    }

private:
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
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}
