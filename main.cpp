#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Include class files in dependency order
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_UpiPayment.cpp"
#include "11_CardPayment.cpp"
#include "12_CashPayment.cpp"
#include "13_PriceCalculator.cpp"
#include "14_TicketPrinter.cpp"

// Display seat information
void displaySeats(vector<ShowSeat>& seats) {

    cout << "\n----------- SEAT LAYOUT -----------\n";

    for (ShowSeat& seat : seats) {

        cout << seat.getSeatNumber() << " | ";

        if (seat.getSeatType() == SeatType::SILVER)
            cout << "SILVER | ";
        else if (seat.getSeatType() == SeatType::GOLD)
            cout << "GOLD | ";
        else
            cout << "PLATINUM | ";

        if (seat.getStatus() == SeatStatus::AVAILABLE)
            cout << "AVAILABLE";
        else
            cout << "BOOKED";

        cout << endl;
    }

    cout << "-----------------------------------\n";
}

// Find a seat by its number
int findSeat(vector<ShowSeat>& seats, string seatNumber) {

    for (int i = 0; i < seats.size(); i++) {

        if (seats[i].getSeatNumber() == seatNumber)
            return i;
    }

    return -1;
}

int main() {

    // =========================================
    // MOVIES
    // =========================================

    Movie movie1("Avengers", "English", 150);
    Movie movie2("3 Idiots", "Hindi", 170);

    vector<Movie> movies = {movie1, movie2};


    // =========================================
    // SHOWS
    // =========================================

    vector<Show> shows;

    shows.push_back(
        Show("Avengers", 1, "06:00 PM")
    );

    shows.push_back(
        Show("Avengers", 2, "09:00 PM")
    );

    shows.push_back(
        Show("3 Idiots", 1, "05:00 PM")
    );


    // =========================================
    // SHOW SEATS
    // =========================================

    vector<ShowSeat> seats;

    seats.push_back(
        ShowSeat("A1", SeatType::SILVER)
    );

    seats.push_back(
        ShowSeat("A2", SeatType::SILVER)
    );

    seats.push_back(
        ShowSeat("B1", SeatType::GOLD)
    );

    seats.push_back(
        ShowSeat("B2", SeatType::GOLD)
    );

    seats.push_back(
        ShowSeat("C1", SeatType::PLATINUM)
    );

    seats.push_back(
        ShowSeat("C2", SeatType::PLATINUM)
    );


    // =========================================
    // BOOKING STORAGE
    // =========================================

    vector<Booking> bookings;

    static int nextBookingId = 1001;


    // =========================================
    // MAIN MENU
    // =========================================

    int choice = 0;

    while (choice != 6) {

        cout << "\n=====================================\n";
        cout << "      MOVIE TICKET BOOKING SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. List Movies\n";
        cout << "2. List Shows\n";
        cout << "3. Display Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;


        // =====================================
        // 1. LIST MOVIES
        // =====================================

        if (choice == 1) {

            cout << "\nCurrently Playing Movies:\n";

            for (int i = 0; i < movies.size(); i++) {

                cout << i + 1 << ". "
                     << movies[i].getTitle()
                     << " | "
                     << movies[i].getLanguage()
                     << " | "
                     << movies[i].getDuration()
                     << " minutes\n";
            }
        }


        // =====================================
        // 2. LIST SHOWS
        // =====================================

        else if (choice == 2) {

            string movieName;

            cout << "\nEnter movie name: ";
            cin >> ws;
            getline(cin, movieName);

            bool found = false;

            cout << "\nAvailable Shows:\n";

            for (Show& show : shows) {

                if (show.getMovieTitle() == movieName) {

                    cout << "Screen "
                         << show.getScreenNumber()
                         << " | "
                         << show.getStartTime()
                         << endl;

                    found = true;
                }
            }

            if (!found)
                cout << "No shows available for this movie.\n";
        }


        // =====================================
        // 3. DISPLAY SEATS
        // =====================================

        else if (choice == 3) {

            displaySeats(seats);
        }


        // =====================================
        // 4. BOOK TICKET
        // =====================================

        else if (choice == 4) {

            string customerName;
            string phone;

            cout << "\nEnter customer name: ";
            cin >> ws;
            getline(cin, customerName);

            cout << "Enter phone number: ";
            cin >> phone;

            Customer customer(customerName, phone);


            // Select movie

            cout << "\nMovies:\n";

            for (int i = 0; i < movies.size(); i++) {

                cout << i + 1 << ". "
                     << movies[i].getTitle()
                     << endl;
            }

            int movieChoice;

            cout << "Select movie: ";
            cin >> movieChoice;

            if (movieChoice < 1 ||
                movieChoice > movies.size()) {

                cout << "Invalid movie selection.\n";
                continue;
            }

            string selectedMovie =
                movies[movieChoice - 1].getTitle();


            // Display shows

            cout << "\nShows for "
                 << selectedMovie
                 << ":\n";

            vector<int> showIndexes;

            for (int i = 0; i < shows.size(); i++) {

                if (shows[i].getMovieTitle() ==
                    selectedMovie) {

                    showIndexes.push_back(i);

                    cout << showIndexes.size()
                         << ". Screen "
                         << shows[i].getScreenNumber()
                         << " | "
                         << shows[i].getStartTime()
                         << endl;
                }
            }

            if (showIndexes.empty()) {

                cout << "No shows available.\n";
                continue;
            }


            // Select show

            int showChoice;

            cout << "Select show: ";
            cin >> showChoice;

            if (showChoice < 1 ||
                showChoice > showIndexes.size()) {

                cout << "Invalid show selection.\n";
                continue;
            }

            Show selectedShow =
                shows[showIndexes[showChoice - 1]];


            // Display seats

            displaySeats(seats);


            // Select seats

            int numberOfSeats;

            cout << "\nNumber of seats: ";
            cin >> numberOfSeats;

            if (numberOfSeats <= 0 ||
                numberOfSeats > seats.size()) {

                cout << "Invalid number of seats.\n";
                continue;
            }

            vector<int> selectedIndexes;
            vector<string> selectedSeatNumbers;
            vector<SeatType> selectedSeatTypes;

            bool invalid = false;


            for (int i = 0; i < numberOfSeats; i++) {

                string seatNumber;

                cout << "Enter seat "
                     << i + 1
                     << ": ";

                cin >> seatNumber;

                int index =
                    findSeat(seats, seatNumber);

                if (index == -1) {

                    cout << "Invalid seat number.\n";
                    invalid = true;
                    break;
                }

                if (seats[index].getStatus()
                    == SeatStatus::BOOKED) {

                    cout << "Seat "
                         << seatNumber
                         << " is already BOOKED.\n";

                    invalid = true;
                    break;
                }

                selectedIndexes.push_back(index);

                selectedSeatNumbers.push_back(
                    seatNumber
                );

                selectedSeatTypes.push_back(
                    seats[index].getSeatType()
                );
            }

            if (invalid)
                continue;


            // Calculate price

            PriceCalculator calculator;

            double totalAmount =
                calculator.calculateTotal(
                    selectedSeatTypes
                );

            cout << "\nTotal Amount: Rs. "
                 << totalAmount
                 << endl;


            // Payment

            cout << "\nPayment Method:\n";
            cout << "1. UPI\n";
            cout << "2. Card\n";
            cout << "3. Cash\n";

            int paymentChoice;

            cout << "Select payment method: ";
            cin >> paymentChoice;

            Payment* payment = nullptr;

            if (paymentChoice == 1)
                payment = new UpiPayment();

            else if (paymentChoice == 2)
                payment = new CardPayment();

            else if (paymentChoice == 3)
                payment = new CashPayment();

            else {

                cout << "Invalid payment method.\n";
                continue;
            }


            // Payment processing

            bool paymentSuccessful =
                payment->pay(totalAmount);


            if (!paymentSuccessful) {

                cout << "Payment failed.\n";
                cout << "Booking not confirmed.\n";

                delete payment;
                continue;
            }


            // Book seats only after successful payment

            for (int index : selectedIndexes)
                seats[index].book();


            // Create booking

            Booking booking(
                nextBookingId++,
                selectedMovie,
                selectedShow.getScreenNumber(),
                selectedShow.getStartTime(),
                selectedSeatNumbers,
                totalAmount
            );

            bookings.push_back(booking);


            // Print ticket

            TicketPrinter printer;

            printer.printTicket(
                booking.getBookingId(),
                booking.getMovieTitle(),
                booking.getScreenNumber(),
                booking.getStartTime(),
                booking.getSeatNumbers(),
                booking.getTotalAmount()
            );

            delete payment;
        }


        // =====================================
        // 5. CANCEL BOOKING
        // =====================================

        else if (choice == 5) {

            int bookingId;

            cout << "\nEnter Booking ID: ";
            cin >> bookingId;

            bool found = false;

            for (Booking& booking : bookings) {

                if (booking.getBookingId() ==
                    bookingId) {

                    if (booking.getStatus() ==
                        BookingStatus::CANCELLED) {

                        cout << "Booking already cancelled.\n";
                        found = true;
                        break;
                    }


                    // Release seats

                    vector<string> bookedSeats =
                        booking.getSeatNumbers();

                    for (string seatNumber :
                         bookedSeats) {

                        int index =
                            findSeat(seats, seatNumber);

                        if (index != -1)
                            seats[index].cancel();
                    }


                    booking.cancel();

                    cout << "Booking cancelled successfully.\n";
                    cout << "Seats are AVAILABLE again.\n";

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Booking ID not found.\n";
        }


        // =====================================
        // INVALID MENU
        // =====================================

        else if (choice != 6) {

            cout << "Invalid menu choice.\n";
        }
    }


    cout << "\nThank you for using the system!\n";

    return 0;
}