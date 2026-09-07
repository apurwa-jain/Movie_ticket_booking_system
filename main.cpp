#include <iostream>
#include <vector>
#include <string>

// Include everything in topological order because of "no header files" constraint
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "06_ShowSeat.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "08_Booking.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

void setupCinema(Cinema& cinema, std::vector<Show*>& shows) {
    Movie* m1 = new Movie("Hanuman Ansh", "Hindi", 170);
    Movie* m2 = new Movie("The Dark Knight", "English", 169);

    Screen* s1 = new Screen(1);
    s1->addSeat(new Seat("A1", "SILVER"));
    s1->addSeat(new Seat("A2", "SILVER"));
    s1->addSeat(new Seat("A3", "SILVER"));
    s1->addSeat(new Seat("A4", "SILVER"));
    s1->addSeat(new Seat("B1", "GOLD"));
    s1->addSeat(new Seat("B2", "GOLD"));
    s1->addSeat(new Seat("B3", "GOLD"));
    s1->addSeat(new Seat("C1", "PLATINUM"));
    s1->addSeat(new Seat("C2", "PLATINUM"));
    
    Screen* s2 = new Screen(2);
    s2->addSeat(new Seat("A1", "SILVER"));
    s2->addSeat(new Seat("B1", "GOLD"));

    cinema.addScreen(s1);
    cinema.addScreen(s2);

    shows.push_back(new Show(m1, s1, "06:00 PM"));
    shows.push_back(new Show(m2, s2, "09:00 PM"));
}

int main() {
    Cinema cinema("PVR Cinemas");
    std::vector<Show*> shows;
    setupCinema(cinema, shows);
    
    BookingService bookingService;
    Customer* cust = new Customer("John Doe", "9999999999");
    
    int choice = 0;
    while(true) {
        std::cout << "===== MOVIE TICKET BOOKING =====\n";
        std::cout << "1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\n";
        std::cout << "Choose: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        if (choice == 0) break;
        
        if (choice == 1) {
            std::cout << "\n";
            for(size_t i=0; i<shows.size(); i++) {
                std::cout << "[" << i+1 << "] " << shows[i]->getMovie()->getTitle() 
                          << "\t" << shows[i]->getMovie()->getLanguage() 
                          << "  " << shows[i]->getMovie()->getDuration() << " min\n";
            }
            std::cout << "\n";
        }
        else if (choice == 2) {
            std::cout << "\nChoose movie (Show):\n";
            for(size_t i=0; i<shows.size(); i++) {
                std::cout << "[" << i+1 << "] Screen-" << shows[i]->getScreen()->getScreenNumber() 
                          << "  " << shows[i]->getStartTime() << " (" << shows[i]->getMovie()->getTitle() << ")\n";
            }
            std::cout << "Choose show: ";
            int showChoice;
            std::cin >> showChoice;
            
            if (showChoice < 1 || showChoice > shows.size()) {
                std::cout << "Invalid show choice.\n\n";
                continue;
            }
            
            Show* selectedShow = shows[showChoice-1];
            while(true) {
                selectedShow->printSeatLayout();
                
                std::cout << "( [ ] = available   [X] = booked )\n\n";
                std::cout << "Seats (e.g. A1,B2): ";
                std::string seatInput;
                std::cin >> seatInput;
                
                // simple CSV parsing
                std::vector<std::string> seatNames;
                size_t pos = 0;
                while ((pos = seatInput.find(',')) != std::string::npos) {
                    seatNames.push_back(seatInput.substr(0, pos));
                    seatInput.erase(0, pos + 1);
                }
                seatNames.push_back(seatInput); // last seat
                
                std::vector<ShowSeat*> selectedShowSeats;
                for(const std::string& sName : seatNames) {
                    for(ShowSeat* ss : selectedShow->getShowSeats()) {
                        if (ss->getSeat()->getSeatNumber() == sName) {
                            selectedShowSeats.push_back(ss);
                            break;
                        }
                    }
                }
                
                if (selectedShowSeats.empty()) {
                    std::cout << "Invalid seat numbers.\n\n";
                    break;
                }
                
                Booking* b = bookingService.bookTicket(cust, selectedShow, selectedShowSeats);
                if (b != nullptr) {
                    std::cout << "TOTAL Rs." << b->getAmount() << "\n";
                    std::cout << "Pay by: 1.UPI  2.Card  3.Cash > ";
                    int payChoice;
                    std::cin >> payChoice;
                    Payment* payment = nullptr;
                    if (payChoice == 1) payment = new UpiPayment();
                    else if (payChoice == 2) payment = new CardPayment();
                    else payment = new CashPayment();
                    
                    bookingService.processPayment(b, payment);
                    break;
                } else {
                    std::cout << "\nSeat not available ,choose another seat\n\n";
                }
            }
            std::cout << "\n";
        }
        else if (choice == 3) {
            std::cout << "Enter Booking ID to cancel: ";
            std::string bId;
            std::cin >> bId;
            bookingService.cancelBooking(bId);
        }
        else if (choice == 4) {
            Booking* latest = bookingService.getLatestBooking();
            if(latest) {
                std::cout << "\nLatest Booking: " << latest->getBookingId() << " - Status: " << latest->getStatus() << "\n\n";
            } else {
                std::cout << "\nNo bookings found.\n\n";
            }
        }
        else {
            std::cout << "Invalid choice.\n\n";
        }
    }

    delete cust;
    // Note: In a real system we should delete shows here, but for simple script it exits
    return 0;
}
