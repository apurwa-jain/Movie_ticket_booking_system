class ShowSeat {
private:
    Seat* seat; // references a physical seat
    bool isBooked;
public:
    ShowSeat(Seat* s) {
        this->seat = s;
        this->isBooked = false;
    }
    Seat* getSeat() const { return seat; }
    bool getStatus() const { return isBooked; }
    void book() { isBooked = true; }
    void release() { isBooked = false; }
};
