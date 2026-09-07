#include <string>

class Movie {
private:
    std::string title;
    std::string language;
    int duration; // in minutes
public:
    Movie(std::string t, std::string l, int d) {
        this->title = t;
        this->language = l;
        this->duration = d;
    }
    std::string getTitle() const { return title; }
    std::string getLanguage() const { return language; }
    int getDuration() const { return duration; }
};
