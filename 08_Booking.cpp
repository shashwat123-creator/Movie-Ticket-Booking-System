#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class BookingStatus {
    CONFIRMED,
    CANCELLED
};

class Booking {
private:
    int bookingId;
    string movieTitle;
    int screenNumber;
    string startTime;
    vector<string> seatNumbers;
    double totalAmount;
    BookingStatus status;

public:
    Booking(int bookingId,
            string movieTitle,
            int screenNumber,
            string startTime,
            vector<string> seatNumbers,
            double totalAmount) {

        this->bookingId = bookingId;
        this->movieTitle = movieTitle;
        this->screenNumber = screenNumber;
        this->startTime = startTime;
        this->seatNumbers = seatNumbers;
        this->totalAmount = totalAmount;
        this->status = BookingStatus::CONFIRMED;
    }

    int getBookingId() {
        return bookingId;
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

    vector<string> getSeatNumbers() {
        return seatNumbers;
    }

    double getTotalAmount() {
        return totalAmount;
    }

    BookingStatus getStatus() {
        return status;
    }

    void cancel() {
        status = BookingStatus::CANCELLED;
    }
};