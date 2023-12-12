#include <iostream>
#include <string>

using namespace std;

// Абстрактний базовий клас
class INotifier {
public:
    virtual void Notify(const string& message) = 0;
};

// Функції для відправки SMS та E-mail
void SendSms(const string& number, const string& message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}

// Реалізація функції Notify
void Notify(INotifier& notifier, const string& message) {
    notifier.Notify(message);
}

// Клас для відправки SMS
class SmsNotifier : public INotifier {
private:
    string phoneNumber;

public:
    SmsNotifier(const string& number) : phoneNumber(number) {}

    // Переозначення методу Notify
    void Notify(const string& message) override {
        SendSms(phoneNumber, message);
    }
};

// Клас для відправки E-mail
class EmailNotifier : public INotifier {
private:
    string emailAddress;

public:
    EmailNotifier(const string& email) : emailAddress(email) {}

    // Переозначення методу Notify
    void Notify(const string& message) override {
        SendEmail(emailAddress, message);
    }
};

int main() {
    SmsNotifier sms{ "+38-067-777-77-77" };
    EmailNotifier email{ "lab28-final@pnu.edu.ua" };

    Notify(sms, "I am learning C++");
    Notify(email, "and I want to be successful");

    return 0;
}
