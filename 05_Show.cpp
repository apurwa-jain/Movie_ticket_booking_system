#include <string>
#include <vector>
#include <iostream>

class Show {
private:
    Movie* movie; // aggregation
    Screen* screen; // aggregation
    std::string startTime;
    std::vector<ShowSeat*> showSeats; // composition
public:
    Show(Movie* m, Screen* s, std::string time) {
        this->movie = m;
        this->screen = s;
        this->startTime = time;
        
        // Create ShowSeats based on Screen's Seats
        for(Seat* seat : s->getSeats()) {
            showSeats.push_back(new ShowSeat(seat));
        }
    }
    
    ~Show() {
        for(ShowSeat* ss : showSeats) {
            delete ss;
        }
        showSeats.clear();
    }

    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    std::string getStartTime() const { return startTime; }
    std::vector<ShowSeat*> getShowSeats() const { return showSeats; }
    
    // Print seat layout
    void printSeatLayout() const {
        std::cout << "SCREEN-" << screen->getScreenNumber() << "  " << startTime << " | " << movie->getTitle() << "\n";
        for(ShowSeat* ss : showSeats) {
            std::cout << ss->getSeat()->getType() << " " << ss->getSeat()->getSeatNumber();
            if (ss->getStatus()) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
        }
        std::cout << "\n\n";
    }
};
