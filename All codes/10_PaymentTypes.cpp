#include <iostream>

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[UPI] Rs." << amount << " paid successfully\n";
        return true;
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[Card] Rs." << amount << " paid successfully\n";
        return true;
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "[Cash] Rs." << amount << " paid successfully\n";
        return true;
    }
};
