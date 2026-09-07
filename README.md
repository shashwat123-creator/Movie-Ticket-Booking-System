# 🎬 Movie Ticket Booking System

<div align="center">

### Low-Level Design (LLD) Project in C++

A menu-driven movie ticket booking system designed using  
**Object-Oriented Programming, Low-Level Design and SOLID Principles**

<br>

`C++17` • `OOP` • `LLD` • `SOLID` • `Console Application`

</div>

---

## 📌 Project Overview

The **Movie Ticket Booking System** is a C++ console application designed for a
**single cinema**.

The project focuses on applying Low-Level Design concepts by dividing the
system into well-defined classes with clear responsibilities and relationships.

The system supports the complete basic booking workflow:

```text
Movie
  ↓
Show
  ↓
Seat Selection
  ↓
Price Calculation
  ↓
Payment
  ↓
Booking
  ↓
Ticket
| Feature              | Description                                    |
| -------------------- | ---------------------------------------------- |
| 🎥 Movie Listing     | View all currently playing movies              |
| 🕐 Show Listing      | View shows for a selected movie                |
| 💺 Seat Layout       | View seat number, type and availability        |
| 🎟️ Seat Booking     | Book one or more seats                         |
| 💰 Price Calculation | Calculate price based on seat type             |
| 💳 Payment           | UPI, Card and Cash payment options             |
| 🧾 Ticket Generation | Print booking details after successful payment |
| ❌ Cancellation       | Cancel an existing booking                     |
| 🔄 Seat Release      | Cancelled seats become AVAILABLE again         |

| Seat Type | Price |
| --------- | ----: |
| SILVER    |  ₹150 |
| GOLD      |  ₹250 |
| PLATINUM  |  ₹400 |

| Class             | Responsibility                                                |
| ----------------- | ------------------------------------------------------------- |
| `Movie`           | Stores movie information                                      |
| `Seat`            | Represents a physical cinema seat                             |
| `Screen`          | Represents a cinema screen and owns physical seats            |
| `Cinema`          | Represents the cinema                                         |
| `Show`            | Represents a movie screening on a screen at a particular time |
| `ShowSeat`        | Maintains seat status for a particular show                   |
| `Customer`        | Stores customer information                                   |
| `Booking`         | Represents a customer's booking                               |
| `Payment`         | Abstract payment contract                                     |
| `UpiPayment`      | UPI payment implementation                                    |
| `CardPayment`     | Card payment implementation                                   |
| `CashPayment`     | Cash payment implementation                                   |
| `PriceCalculator` | Calculates total booking amount                               |
| `TicketPrinter`   | Prints ticket information                                     |
| `BookingService`  | Coordinates the booking workflow                              |

Customer
   │
   ▼
Select Movie
   │
   ▼
Select Show
   │
   ▼
Display Seat Layout
   │
   ▼
Select One or More Seats
   │
   ▼
Validate Seat Availability
   │
   ├──────── Seat Already BOOKED
   │                 │
   │                 ▼
   │             Reject Booking
   │
   ▼
Calculate Total Price
   │
   ▼
Select Payment Method
   │
   ▼
Process Payment
   │
   ├──────── Payment Failed
   │                 │
   │                 ▼
   │             Release Seats
   │                 │
   │                 ▼
   │           Booking Not Confirmed
   │
   ▼
Create Booking
   │
   ▼
Print Ticket

                 Payment
                «abstract»
                    │
        ┌───────────┼───────────┐
        │           │           │
        ▼           ▼           ▼
   UpiPayment  CardPayment  CashPayment

| Test Case                                        |  Result  |
| ------------------------------------------------ | :------: |
| List all currently playing movies                | ✅ Passed |
| List shows for selected movie                    | ✅ Passed |
| Display seats for selected show                  | ✅ Passed |
| Maintain separate seat state for different shows | ✅ Passed |
| Book multiple available seats                    | ✅ Passed |
| Calculate price according to seat type           | ✅ Passed |
| Successful UPI payment                           | ✅ Passed |
| Reject already-booked seat                       | ✅ Passed |
| Generate ticket after successful payment         | ✅ Passed |
| Cancel existing booking                          | ✅ Passed |
| Release seats after cancellation                 | ✅ Passed |

Movie-Ticket-Booking-System(lld)/
│
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_UpiPayment.cpp
├── 11_CardPayment.cpp
├── 12_CashPayment.cpp
├── 13_PriceCalculator.cpp
├── 14_TicketPrinter.cpp
├── 15_BookingService.cpp
│
├── main.cpp
├── README.md
│
├── docs/
│   └── LLD ASSIGNMENT.pdf
│
└── screenshots/
    ├── SS-LLD1
    └── SSLLD2.jpg

The system design applies the following SOLID principles.

1. S — Single Responsibility Principle

Each major class has a focused responsibility.

Examples:

PriceCalculator  → Calculates booking price

TicketPrinter    → Prints ticket

BookingService   → Coordinates booking workflow

Movie            → Stores movie information

Customer         → Stores customer information

This keeps the classes easier to understand, maintain and modify.

2. O — Open/Closed Principle

The payment system is designed so that new payment methods can be added
without changing the existing payment implementations.

Current implementations:

Payment
   ├── UpiPayment
   ├── CardPayment
   └── CashPayment

A future implementation could be:

Payment
   ├── UpiPayment
   ├── CardPayment
   ├── CashPayment
   └── WalletPayment
3. L — Liskov Substitution Principle

UpiPayment, CardPayment and CashPayment are derived from the
Payment abstraction.

Therefore, the booking workflow can work with a Payment object without
depending on a particular payment implementation.

Payment
   ↑
   ├── UpiPayment
   ├── CardPayment
   └── CashPayment
4. I — Interface Segregation Principle

The payment abstraction is kept small and focused on the operation required
by the booking workflow.

The system does not force payment implementations to depend on unrelated
operations.

5. D — Dependency Inversion Principle

The booking workflow works with the abstract Payment type instead of being
tightly coupled to one specific payment method.

Conceptually:

BookingService
      │
      ▼
   Payment
   /  |  \
  /   |   \
UPI  Card Cash

This reduces direct dependency on concrete payment implementations.

🚧 Deliberate Scope Limitation

One feature was deliberately not implemented:

❌ Real Payment Gateway Integration

The project does not connect to real payment gateways such as actual UPI,
banking or card-processing APIs.

Instead, payment processing is simulated through:

UPI
Card
Cash
Why?

The objective of this academic project is to demonstrate:

Object-Oriented Design
        +
Class Relationships
        +
Booking Workflow
        +
SOLID Principles

rather than implementing production-level payment infrastructure.

Keeping real payment gateway integration outside the scope makes the project
smaller and focused on the required Low-Level Design concepts.

🛠️ Technology Stack
Technology	Usage
C++	Application development
C++17	Language standard
OOP	Object-oriented design
LLD	System design approach
Clang++	Compilation
Console	User interface
Git & GitHub	Version control
▶️ How to Run
1. Clone the Repository
git clone https://github.com/shashwat123-creator/Movie-Ticket-Booking-System.git
2. Open the Project
cd Movie-Ticket-Booking-System
3. Compile
clang++ -std=c++17 main.cpp -o movie_booking
4. Run
./movie_booking

## 📐 UML Class Diagram

![UML Class Diagram](docs/uml.jpeg)

## 🔄 Sequence Diagram

![Sequence Diagram](docs/sequence.jpeg)

## 🧩 SOLID Principles
