#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

// ���� PhoneNumber ��� ������������� ����������� ������
class PhoneNumber {
public:
    // ����������� �����, ������ ���������� ����� ��������
    explicit PhoneNumber(const string& international_number) {
        // ����������� ������� ������� � ������� '-' � ����������� �����
        size_t first_dash = international_number.find('-');
        size_t second_dash = international_number.find('-', first_dash + 1);

        // �������� ����������� �������, ����� ���������� � '+' � �� ��� '-' �������
        if (first_dash == string::npos || second_dash == string::npos || international_number[0] != '+') {
            // ��������� ����������� ��� ������� �� ��������� ������� invalid_argument
            cout << "The phone number must start with a '+' symbol and contain 3 parts separated by '-' symbols: " << international_number << endl;
            throw invalid_argument("");
        }

        // ��������� ���� �����, ���� �� ������ � ����������� ������
        country_code_ = international_number.substr(1, first_dash - 1);
        city_code_ = international_number.substr(first_dash + 1, second_dash - first_dash - 1);
        local_number_ = international_number.substr(second_dash + 1);

        // ��������, �� ���� � ��������� ���������� � �������
        if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
            // ��������� ����������� ��� ������� �� ��������� ������� invalid_argument
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