#include <string>

class Seat {
private:
    std::string seatNumber;
    std::string type;
public:
    Seat(std::string num, std::string t) {
        this->seatNumber = num;
        this->type = t;
    }
    std::string getSeatNumber() const { return seatNumber; }
    std::string getType() const { return type; }
};
