#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cinema {
private:
    string name;
    vector<int> screenNumbers;

public:
    Cinema(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void addScreen(int screenNumber) {
        screenNumbers.push_back(screenNumber);
    }

    vector<int> getScreenNumbers() {
        return screenNumbers;
    }
};