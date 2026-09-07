#include <vector>
#include <iostream>

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    std::vector<Booking*> allBookings;

public:
    ~BookingService() {
        for(Booking* b : allBookings) {
            delete b;
        }
        allBookings.clear();
    }

    Booking* bookTicket(Customer* customer, Show* show, const std::vector<ShowSeat*>& selectedSeats) {
        // Validate if ANY seat is already booked
        for(ShowSeat* ss : selectedSeats) {
            if(ss->getStatus() == true) {
                return nullptr; // reject booking
            }
        }

        double amount = priceCalculator.calculateTotal(selectedSeats);
        Booking* b = new Booking(customer, show, selectedSeats, amount);
        allBookings.push_back(b);
        return b;
    }

    bool processPayment(Booking* booking, Payment* payment) {
        booking->setPayment(payment);
        bool success = payment->pay(booking->getAmount());
        if(success) {
            booking->confirm();
            ticketPrinter.print(booking);
            return true;
        } else {
            booking->fail();
            return false;
        }
    }

    bool cancelBooking(std::string bookingId) {
        for(Booking* b : allBookings) {
            if(b->getBookingId() == bookingId) {
                b->cancel();
                std::cout << "\nBooking " << bookingId << " has been cancelled. Seats are now AVAILABLE.\n";
                return true;
            }
        }
        std::cout << "\nError: Booking ID not found.\n";
        return false;
    }
    
    // For demo purposes: get latest booking
    Booking* getLatestBooking() {
        if(allBookings.empty()) return nullptr;
        return allBookings.back();
    }
};
