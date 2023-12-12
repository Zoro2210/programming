#include <iostream>
#include <sstream>
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

    Rational operator*(const Rational& other) const {
        int new_numerator = numerator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return Rational(new_numerator, new_denominator);
    }

    Rational operator/(const Rational& other) const {
        int new_numerator = numerator_ * other.denominator_;
        int new_denominator = denominator_ * other.numerator_;
        return Rational(new_numerator, new_denominator);
    }

    friend ostream& operator<<(ostream& stream, const Rational& rational);
    friend istream& operator>>(istream& stream, Rational& rational);

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

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int numerator, denominator;
    char delimiter;
    stream >> numerator >> delimiter >> denominator;
    if (stream && delimiter == '/') {
        rational = Rational(numerator, denominator);
    }
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }
    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }
    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }
        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }
    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;
            return 6;
        }
    }
    cout << "OK" << endl;
    return 0;
}
