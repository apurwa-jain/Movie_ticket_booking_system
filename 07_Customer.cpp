#include <string>

class Customer {
private:
    std::string name;
    std::string phone;
public:
    Customer(std::string n, std::string p) {
        this->name = n;
        this->phone = p;
    }
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
};
