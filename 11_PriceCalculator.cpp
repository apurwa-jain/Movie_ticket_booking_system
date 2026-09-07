#include <vector>
#include <string>

class PriceCalculator {
private:
    const double SILVER_PRICE = 150.0;
    const double GOLD_PRICE = 250.0;
    const double PLATINUM_PRICE = 400.0;

public:
    double calculateTotal(const std::vector<ShowSeat*>& seats) {
        double total = 0.0;
        for(ShowSeat* ss : seats) {
            std::string type = ss->getSeat()->getType();
            if(type == "SILVER") {
                total += SILVER_PRICE;
            } else if(type == "GOLD") {
                total += GOLD_PRICE;
            } else if(type == "PLATINUM") {
                total += PLATINUM_PRICE;
            }
        }
        return total;
    }
};
