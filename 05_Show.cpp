#include <iostream>
#include <string>
using namespace std;

class Show {
private:
    string movieTitle;
    int screenNumber;
    string startTime;

public:
    Show(string movieTitle, int screenNumber, string startTime) {
        this->movieTitle = movieTitle;
        this->screenNumber = screenNumber;
        this->startTime = startTime;
    }

    string getMovieTitle() {
        return movieTitle;
    }

    int getScreenNumber() {
        return screenNumber;
    }

    string getStartTime() {
        return startTime;
    }
};