#include <string>
#include <vector>

class Cinema {
private:
    std::string name;
    std::vector<Screen*> screens;
public:
    Cinema(std::string n) {
        this->name = n;
    }
    
    ~Cinema() {
        for(Screen* s : screens) {
            delete s;
        }
        screens.clear();
    }

    void addScreen(Screen* s) {
        screens.push_back(s);
    }

    std::string getName() const { return name; }
    std::vector<Screen*> getScreens() const { return screens; }
};
