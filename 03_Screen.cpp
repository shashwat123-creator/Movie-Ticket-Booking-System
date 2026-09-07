#include <iostream>
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;

public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }

    int getScreenNumber() {
        return screenNumber;
    }
};