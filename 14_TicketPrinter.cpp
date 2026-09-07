#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TicketPrinter {
public:
    void printTicket(
        int bookingId,
        string movieTitle,
        int screenNumber,
        string startTime,
        vector<string> seatNumbers,
        double totalAmount
    ) {
        cout << "\n====================================\n";
        cout << "          MOVIE TICKET              \n";
        cout << "====================================\n";

        cout << "Booking ID : " << bookingId << endl;
        cout << "Movie      : " << movieTitle << endl;
        cout << "Screen     : " << screenNumber << endl;
        cout << "Show Time  : " << startTime << endl;

        cout << "Seats      : ";
        for (string seat : seatNumbers) {
            cout << seat << " ";
        }

        cout << "\nTotal      : Rs. " << totalAmount << endl;

        cout << "====================================\n";
        cout << "       Booking Confirmed!            \n";
        cout << "====================================\n";
    }
};