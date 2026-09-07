#include <iostream>
#include <string>
using namespace std;

enum class SeatType {
    SILVER,
    GOLD,
    PLATINUM
};

class Seat {
private:
    string seatNumber;
    SeatType seatType;

public:
    Seat(string seatNumber, SeatType seatType) {
        this->seatNumber = seatNumber;
        this->seatType = seatType;
    }

    string getSeatNumber() {
        return seatNumber;
    }

    SeatType getSeatType() {
        return seatType;
    }
};