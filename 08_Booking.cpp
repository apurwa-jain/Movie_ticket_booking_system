#include <string>
#include <vector>

class Booking {
private:
    static int nextBookingId;
    std::string bookingId;
    Customer* customer; // aggregation
    Show* show; // aggregation
    std::vector<ShowSeat*> seats; // aggregation
    double amount;
    std::string status; // "PENDING", "CONFIRMED", "FAILED"
    Payment* payment; // composition

public:
    Booking(Customer* c, Show* s, std::vector<ShowSeat*> st, double amt) {
        this->bookingId = "BK" + std::to_string(nextBookingId++);
        this->customer = c;
        this->show = s;
        this->seats = st;
        this->amount = amt;
        this->status = "PENDING";
        this->payment = nullptr;
    }
    
    ~Booking() {
        if (payment != nullptr) {
            delete payment;
        }
    }

    void setPayment(Payment* p) {
        this->payment = p;
    }
    
    void confirm() {
        this->status = "CONFIRMED";
        for (ShowSeat* ss : seats) {
            ss->book();
        }
    }

    void fail() {
        this->status = "FAILED";
        for (ShowSeat* ss : seats) {
            ss->release(); // strictly ensure seats are available
        }
    }
    
    void cancel() {
        this->status = "CANCELLED";
        for (ShowSeat* ss : seats) {
            ss->release(); // make seats available again
        }
    }
    
    std::string getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    std::vector<ShowSeat*> getSeats() const { return seats; }
    double getAmount() const { return amount; }
    std::string getStatus() const { return status; }
};

// Initialize static member
int Booking::nextBookingId = 1001;
