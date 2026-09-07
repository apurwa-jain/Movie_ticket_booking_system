#include <iostream>
#include <vector>

class TicketPrinter {
public:
    void print(Booking* b) {
        std::cout << "\n================ TICKET ================\n";
        std::cout << " Booking ID : " << b->getBookingId() << "\n";
        std::cout << " Movie      : " << b->getShow()->getMovie()->getTitle() << "\n";
        std::cout << " Screen     : Screen-" << b->getShow()->getScreen()->getScreenNumber() << "    " << b->getShow()->getStartTime() << "\n";
        
        std::cout << " Seats      : ";
        std::vector<ShowSeat*> seats = b->getSeats();
        for (size_t i = 0; i < seats.size(); ++i) {
            std::cout << seats[i]->getSeat()->getSeatNumber();
            if (i < seats.size() - 1) std::cout << ", ";
        }
        std::cout << "\n Amount     : Rs." << b->getAmount() << "      Status: " << b->getStatus() << "\n";
        std::cout << "========================================\n\n";
    }
};
