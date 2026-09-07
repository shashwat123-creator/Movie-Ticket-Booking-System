#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BookingService {
private:
    vector<Booking> bookings;
    static int nextBookingId;

public:
    BookingService() {}

    bool areSeatsAvailable(vector<ShowSeat>& seats) {
        for (ShowSeat& seat : seats) {
            if (seat.getStatus() == SeatStatus::BOOKED) {
                return false;
            }
        }

        return true;
    }

    void bookSeats(vector<ShowSeat>& seats) {
        for (ShowSeat& seat : seats) {
            seat.book();
        }
    }

    void releaseSeats(vector<ShowSeat>& seats) {
        for (ShowSeat& seat : seats) {
            seat.cancel();
        }
    }

    int generateBookingId() {
        return nextBookingId++;
    }

    void addBooking(Booking booking) {
        bookings.push_back(booking);
    }

    Booking* findBooking(int bookingId) {
        for (Booking& booking : bookings) {
            if (booking.getBookingId() == bookingId) {
                return &booking;
            }
        }

        return nullptr;
    }
};

int BookingService::nextBookingId = 1001;