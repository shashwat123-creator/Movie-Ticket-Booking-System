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
#include "15_BookingService.cpp"


// =====================================================
// DISPLAY SEATS
// =====================================================

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


// =====================================================
// FIND SEAT
// =====================================================

int findSeat(vector<ShowSeat>& seats, string seatNumber) {

    for (int i = 0; i < seats.size(); i++) {

        if (seats[i].getSeatNumber() == seatNumber)
            return i;
    }

    return -1;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // =================================================
    // MOVIES
    // =================================================

    Movie movie1("Avengers", "English", 150);
    Movie movie2("3 Idiots", "Hindi", 170);

    vector<Movie> movies = {
        movie1,
        movie2
    };


    // =================================================
    // SHOWS
    // =================================================

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


    // =================================================
    // SHOW SEATS
    //
    // Each show gets its own seat layout.
    // =================================================

    vector<vector<ShowSeat>> showSeats;


    // Seats for Avengers - Screen 1
    vector<ShowSeat> seats1;

    seats1.push_back(
        ShowSeat("A1", SeatType::SILVER)
    );

    seats1.push_back(
        ShowSeat("A2", SeatType::SILVER)
    );

    seats1.push_back(
        ShowSeat("B1", SeatType::GOLD)
    );

    seats1.push_back(
        ShowSeat("B2", SeatType::GOLD)
    );

    seats1.push_back(
        ShowSeat("C1", SeatType::PLATINUM)
    );

    seats1.push_back(
        ShowSeat("C2", SeatType::PLATINUM)
    );


    // Seats for Avengers - Screen 2
    vector<ShowSeat> seats2;

    seats2.push_back(
        ShowSeat("A1", SeatType::SILVER)
    );

    seats2.push_back(
        ShowSeat("A2", SeatType::SILVER)
    );

    seats2.push_back(
        ShowSeat("B1", SeatType::GOLD)
    );

    seats2.push_back(
        ShowSeat("B2", SeatType::GOLD)
    );

    seats2.push_back(
        ShowSeat("C1", SeatType::PLATINUM)
    );

    seats2.push_back(
        ShowSeat("C2", SeatType::PLATINUM)
    );


    // Seats for 3 Idiots - Screen 1
    vector<ShowSeat> seats3;

    seats3.push_back(
        ShowSeat("A1", SeatType::SILVER)
    );

    seats3.push_back(
        ShowSeat("A2", SeatType::SILVER)
    );

    seats3.push_back(
        ShowSeat("B1", SeatType::GOLD)
    );

    seats3.push_back(
        ShowSeat("B2", SeatType::GOLD)
    );

    seats3.push_back(
        ShowSeat("C1", SeatType::PLATINUM)
    );

    seats3.push_back(
        ShowSeat("C2", SeatType::PLATINUM)
    );


    showSeats.push_back(seats1);
    showSeats.push_back(seats2);
    showSeats.push_back(seats3);


    // =================================================
    // SERVICES
    // =================================================

    BookingService bookingService;
    PriceCalculator calculator;
    TicketPrinter printer;


    // =================================================
    // MAIN MENU
    // =================================================

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


        // =================================================
        // 1. LIST MOVIES
        // =================================================

        if (choice == 1) {

            cout << "\n===== CURRENTLY PLAYING MOVIES =====\n";

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


        // =================================================
        // 2. LIST SHOWS
        // =================================================

        else if (choice == 2) {

            cout << "\n===== MOVIES =====\n";

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

            string movieName =
                movies[movieChoice - 1].getTitle();

            bool found = false;

            cout << "\n===== AVAILABLE SHOWS =====\n";

            for (int i = 0; i < shows.size(); i++) {

                if (shows[i].getMovieTitle() == movieName) {

                    cout << "Screen "
                         << shows[i].getScreenNumber()
                         << " | "
                         << shows[i].getStartTime()
                         << endl;

                    found = true;
                }
            }

            if (!found)
                cout << "No shows available for this movie.\n";
        }


        // =================================================
        // 3. DISPLAY SEATS
        // =================================================

        else if (choice == 3) {

            cout << "\n===== MOVIES =====\n";

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


            cout << "\n===== SHOWS =====\n";

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

            int showChoice;

            cout << "Select show: ";
            cin >> showChoice;

            if (showChoice < 1 ||
                showChoice > showIndexes.size()) {

                cout << "Invalid show selection.\n";
                continue;
            }

            int selectedShowIndex =
                showIndexes[showChoice - 1];

            cout << "\n"
                 << selectedMovie
                 << " | Screen "
                 << shows[selectedShowIndex].getScreenNumber()
                 << " | "
                 << shows[selectedShowIndex].getStartTime()
                 << endl;

            displaySeats(showSeats[selectedShowIndex]);
        }


        // =================================================
        // 4. BOOK TICKET
        // =================================================

        else if (choice == 4) {

            string customerName;
            string phone;

            cout << "\nEnter customer name: ";
            cin >> ws;
            getline(cin, customerName);

            cout << "Enter phone number: ";
            cin >> phone;

            Customer customer(
                customerName,
                phone
            );


            // ---------------------------------------------
            // SELECT MOVIE
            // ---------------------------------------------

            cout << "\n===== MOVIES =====\n";

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


            // ---------------------------------------------
            // SELECT SHOW
            // ---------------------------------------------

            cout << "\n===== SHOWS FOR "
                 << selectedMovie
                 << " =====\n";

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

            int showChoice;

            cout << "Select show: ";
            cin >> showChoice;

            if (showChoice < 1 ||
                showChoice > showIndexes.size()) {

                cout << "Invalid show selection.\n";
                continue;
            }

            int selectedShowIndex =
                showIndexes[showChoice - 1];

            Show selectedShow =
                shows[selectedShowIndex];


            // ---------------------------------------------
            // DISPLAY SEATS FOR SELECTED SHOW
            // ---------------------------------------------

            cout << "\n===== SEATS =====\n";

            displaySeats(
                showSeats[selectedShowIndex]
            );


            // ---------------------------------------------
            // SELECT NUMBER OF SEATS
            // ---------------------------------------------

            int numberOfSeats;

            cout << "\nNumber of seats: ";
            cin >> numberOfSeats;

            if (numberOfSeats <= 0 ||
                numberOfSeats >
                showSeats[selectedShowIndex].size()) {

                cout << "Invalid number of seats.\n";
                continue;
            }


            vector<int> selectedIndexes;
            vector<string> selectedSeatNumbers;
            vector<SeatType> selectedSeatTypes;

            bool invalid = false;


            // ---------------------------------------------
            // SELECT INDIVIDUAL SEATS
            // ---------------------------------------------

            for (int i = 0; i < numberOfSeats; i++) {

                string seatNumber;

                cout << "Enter seat "
                     << i + 1
                     << ": ";

                cin >> seatNumber;

                int index =
                    findSeat(
                        showSeats[selectedShowIndex],
                        seatNumber
                    );


                // Invalid seat
                if (index == -1) {

                    cout << "Invalid seat number.\n";
                    invalid = true;
                    break;
                }


                // Check duplicate selection
                bool alreadySelected = false;

                for (int selected : selectedIndexes) {

                    if (selected == index) {

                        alreadySelected = true;
                        break;
                    }
                }

                if (alreadySelected) {

                    cout << "Seat "
                         << seatNumber
                         << " already selected.\n";

                    invalid = true;
                    break;
                }


                // Check whether already booked
                if (showSeats[selectedShowIndex][index]
                        .getStatus()
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
                    showSeats[selectedShowIndex][index]
                        .getSeatType()
                );
            }


            // If any seat selection failed,
            // do not modify any seat.
            if (invalid)
                continue;


            // ---------------------------------------------
            // CALCULATE PRICE
            // ---------------------------------------------

            double totalAmount =
                calculator.calculateTotal(
                    selectedSeatTypes
                );

            cout << "\nTotal Amount: Rs. "
                 << totalAmount
                 << endl;


            // ---------------------------------------------
            // PAYMENT
            // ---------------------------------------------

            cout << "\n===== PAYMENT METHOD =====\n";

            cout << "1. UPI\n";
            cout << "2. Card\n";
            cout << "3. Cash\n";

            int paymentChoice;

            cout << "Select payment method: ";
            cin >> paymentChoice;

            Payment* payment = nullptr;


            if (paymentChoice == 1) {

                payment = new UpiPayment();
            }

            else if (paymentChoice == 2) {

                payment = new CardPayment();
            }

            else if (paymentChoice == 3) {

                payment = new CashPayment();
            }

            else {

                cout << "Invalid payment method.\n";
                continue;
            }


            // ---------------------------------------------
            // PROCESS PAYMENT
            // ---------------------------------------------

            bool paymentSuccessful =
                payment->pay(totalAmount);


            // Payment failed
            if (!paymentSuccessful) {

                cout << "\nPayment failed.\n";
                cout << "Booking NOT confirmed.\n";

                delete payment;

                continue;
            }


            // ---------------------------------------------
            // BOOK SEATS
            //
            // Seats are changed only after successful
            // payment.
            // ---------------------------------------------

            for (int index : selectedIndexes) {

                showSeats[selectedShowIndex][index].book();
            }


            // ---------------------------------------------
            // CREATE BOOKING
            // ---------------------------------------------

            int bookingId =
                bookingService.generateBookingId();


            Booking booking(
                bookingId,
                selectedMovie,
                selectedShow.getScreenNumber(),
                selectedShow.getStartTime(),
                selectedSeatNumbers,
                totalAmount
            );


            bookingService.addBooking(booking);


            // ---------------------------------------------
            // PRINT TICKET
            // ---------------------------------------------

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


        // =================================================
        // 5. CANCEL BOOKING
        // =================================================

        else if (choice == 5) {

            int bookingId;

            cout << "\nEnter Booking ID: ";
            cin >> bookingId;


            Booking* booking =
                bookingService.findBooking(
                    bookingId
                );


            if (booking == nullptr) {

                cout << "Booking ID not found.\n";
                continue;
            }


            // Already cancelled
            if (booking->getStatus() ==
                BookingStatus::CANCELLED) {

                cout << "Booking already cancelled.\n";
                continue;
            }


            // ---------------------------------------------
            // FIND THE CORRECT SHOW
            // ---------------------------------------------

            int matchedShowIndex = -1;

            for (int i = 0; i < shows.size(); i++) {

                if (shows[i].getMovieTitle() ==
                        booking->getMovieTitle() &&

                    shows[i].getScreenNumber() ==
                        booking->getScreenNumber() &&

                    shows[i].getStartTime() ==
                        booking->getStartTime()) {

                    matchedShowIndex = i;
                    break;
                }
            }


            if (matchedShowIndex == -1) {

                cout << "Associated show not found.\n";
                continue;
            }


            // ---------------------------------------------
            // RELEASE SEATS
            // ---------------------------------------------

            vector<string> bookedSeats =
                booking->getSeatNumbers();


            for (string seatNumber : bookedSeats) {

                int index =
                    findSeat(
                        showSeats[matchedShowIndex],
                        seatNumber
                    );

                if (index != -1) {

                    showSeats[matchedShowIndex][index]
                        .cancel();
                }
            }


            // ---------------------------------------------
            // CANCEL BOOKING
            // ---------------------------------------------

            booking->cancel();


            cout << "\nBooking cancelled successfully.\n";
            cout << "Seats are AVAILABLE again.\n";
        }


        // =================================================
        // INVALID MENU
        // =================================================

        else if (choice != 6) {

            cout << "Invalid menu choice.\n";
        }
    }


    cout << "\nThank you for using the system!\n";

    return 0;
}