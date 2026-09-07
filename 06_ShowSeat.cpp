#include <iostream>
#include <string>
using namespace std;

enum class SeatStatus {
    AVAILABLE,
    BOOKED
};

class ShowSeat {
private:
    string seatNumber;
    SeatType seatType;
    SeatStatus status;

public:
    ShowSeat(string seatNumber, SeatType seatType) {
        this->seatNumber = seatNumber;
        this->seatType = seatType;
        this->status = SeatStatus::AVAILABLE;
    }

    string getSeatNumber() {
        return seatNumber;
    }

    SeatType getSeatType() {
        return seatType;
    }

    SeatStatus getStatus() {
        return status;
    }

    bool book() {
        if (status == SeatStatus::BOOKED) {
            return false;
        }

        status = SeatStatus::BOOKED;
        return true;
    }

    void cancel() {
        status = SeatStatus::AVAILABLE;
    }
};