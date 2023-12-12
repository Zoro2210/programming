#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

// Клас PhoneNumber для представлення телефонного номера
class PhoneNumber {
public:
    // Конструктор класу, приймає міжнародний номер телефону
    explicit PhoneNumber(const string& international_number) {
        // Знаходження позицій першого і другого '-' у міжнародному номері
        size_t first_dash = international_number.find('-');
        size_t second_dash = international_number.find('-', first_dash + 1);

        // Перевірка правильності формату, тобто починається з '+' і має два '-' символи
        if (first_dash == string::npos || second_dash == string::npos || international_number[0] != '+') {
            // Виведення повідомлення про помилку та викидання винятку invalid_argument
            cout << "The phone number must start with a '+' symbol and contain 3 parts separated by '-' symbols: " << international_number << endl;
            throw invalid_argument("");
        }

        // Видобуття коду країни, міста та номеру з міжнародного номеру
        country_code_ = international_number.substr(1, first_dash - 1);
        city_code_ = international_number.substr(first_dash + 1, second_dash - first_dash - 1);
        local_number_ = international_number.substr(second_dash + 1);

        // Перевірка, чи один з видобутих компонентів є порожнім
        if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
            // Виведення повідомлення про помилку та викидання винятку invalid_argument
            cout << "The phone number must start with a '+' symbol and contain 3 parts separated by '-' symbols: " << international_number << endl;
            throw invalid_argument("");
        }
    }

    string GetCountryCode() const {
        return country_code_;
    }

    string GetCityCode() const {
        return city_code_;
    }

    string GetLocalNumber() const {
        return local_number_;
    }

    string GetInternationalNumber() const {
        return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
    }

private:
    string country_code_;
    string city_code_;
    string local_number_;
};