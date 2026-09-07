#include <string>
#include <vector>

// Forward declaration if needed, but since we use unity build, Seat will be included first.
class Screen {
private:
    int screenNumber;
    std::vector<Seat*> seats; // Aggregation/Composition depending on initialization
public:
    Screen(int num) {
        this->screenNumber = num;
    }
    
    // Destructor to clean up composition
    ~Screen() {
        for(Seat* s : seats) {
            delete s;
        }
        seats.clear();
    }

    void addSeat(Seat* s) {
        seats.push_back(s);
    }
    
    int getScreenNumber() const { return screenNumber; }
    std::vector<Seat*> getSeats() const { return seats; }
};
