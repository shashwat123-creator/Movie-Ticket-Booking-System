🎬 Movie Ticket Booking System
<div align="center">
A C++ Low-Level Design Project

A modular, object-oriented movie ticket booking system for a single cinema

<br>








<br><br>

Movies → Shows → Seats → Payment → Booking → Ticket

</div>
📌 About The Project

The Movie Ticket Booking System is a menu-driven C++ console application designed using Object-Oriented Programming and Low-Level Design principles.

The system models the core workflow of a cinema booking platform while keeping the implementation focused on a single cinema.

🎯 What can a customer do?
🎥 Movies	🕐 Shows	💺 Seats	🎟️ Booking
View movies	View shows	Check availability	Book seats
		Select multiple seats	Cancel booking
💳 Payment Methods
UPI
Card
Cash
💰 Seat Categories
Category	Price
🥈 SILVER	₹150
🥇 GOLD	₹250
💎 PLATINUM	₹400
🏗️ System Architecture
                         ┌─────────────────┐
                         │    Customer     │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │ BookingService  │
                         └────────┬────────┘
                                  │
                ┌─────────────────┼─────────────────┐
                │                 │                 │
                ▼                 ▼                 ▼
           ┌─────────┐      ┌────────────┐    ┌──────────────┐
           │  Movie  │      │    Show    │    │PriceCalculator│
           └─────────┘      └─────┬──────┘    └──────────────┘
                                  │
                                  ▼
                           ┌────────────┐
                           │  ShowSeat  │
                           └─────┬──────┘
                                 │
                                 ▼
                           ┌──────────┐
                           │   Seat   │
                           └──────────┘

                                  │
                                  ▼
                           ┌──────────┐
                           │ Payment  │
                           └────┬─────┘
                                │
                ┌───────────────┼───────────────┐
                ▼               ▼               ▼
           ┌─────────┐     ┌─────────┐     ┌─────────┐
           │   UPI   │     │  Card   │     │  Cash   │
           └─────────┘     └─────────┘     └─────────┘

                                  │
                                  ▼
                           ┌──────────┐
                           │ Booking  │
                           └────┬─────┘
                                │
                                ▼
                         ┌──────────────┐
                         │TicketPrinter │
                         └──────────────┘
✨ Features
🎥 1. Movie Management
Displays currently playing movies
Allows the customer to select a movie
Handles invalid movie selection
🕐 2. Show Management
Displays shows for the selected movie
Shows screen number
Shows start time
💺 3. Seat Management
Displays seat number
Displays seat type
Displays AVAILABLE / BOOKED
Maintains separate seat state for each show
🎟️ 4. Ticket Booking
Supports multiple seats
Prevents booking of already-booked seats
Calculates total amount automatically
Booking is confirmed only after successful payment
💳 5. Payment

Supports:

UPI
Card
Cash

Payment failure does not confirm the booking.

❌ 6. Cancellation
Existing bookings can be cancelled
Associated seats become AVAILABLE again
🔄 Booking Flow
┌──────────┐
│ Customer │
└────┬─────┘
     │
     ▼
Select Movie
     │
     ▼
Select Show
     │
     ▼
View Seats
     │
     ▼
Select Seats
     │
     ▼
Validate Seats
     │
     ▼
Calculate Price
     │
     ▼
Select Payment Method
     │
     ▼
Process Payment
     │
     ├─────────────── Failed ──────────────┐
     │                                    │
     │                                    ▼
     │                             Release Seats
     │                                    │
     │                                    ▼
     │                              Booking Failed
     │
     │ Successful
     ▼
Create Booking
     │
     ▼
Print Ticket
🧩 Major Classes
Class	Responsibility
Movie	Stores movie information
Seat	Represents a physical cinema seat
Screen	Represents a cinema screen
Cinema	Represents the cinema
Show	Represents a movie screening
ShowSeat	Maintains seat status for a show
Customer	Stores customer information
Booking	Represents a booking
Payment	Abstract payment contract
UpiPayment	UPI payment implementation
CardPayment	Card payment implementation
CashPayment	Cash payment implementation
PriceCalculator	Calculates booking price
TicketPrinter	Prints ticket information
BookingService	Coordinates booking workflow
💳 Payment Design

The payment system uses an abstraction:

                     ┌──────────────┐
                     │   Payment    │
                     │  «abstract»  │
                     └───────┬──────┘
                             │
              ┌──────────────┼──────────────┐
              │              │              │
              ▼              ▼              ▼
       ┌────────────┐ ┌────────────┐ ┌────────────┐
       │UpiPayment  │ │CardPayment │ │CashPayment │
       └────────────┘ └────────────┘ └────────────┘

This makes it possible to add another payment method in the future without changing the existing payment implementations.

📐 UML & Design Documentation

All design documentation is available in the docs folder.

📄 Assignment Documentation

👉 Open LLD Assignment PDF

The document contains:

Requirement Analysis
Functional Requirements
Non-Functional Requirements
Noun–Verb Analysis
Relationship Table
Class Diagram
Sequence Diagram
SOLID mapping
Deliberate scope limitation
🖥️ Project Screenshots
🎬 Application Demo
Screenshot 1

Screenshot 2

🧪 Tested Scenarios
Test Scenario	Result
Display all movies	✅
Display shows for selected movie	✅
Display seat layout	✅
Maintain separate seats for different shows	✅
Book multiple seats	✅
Calculate price according to seat type	✅
UPI payment	✅
Reject already booked seats	✅
Generate ticket	✅
Cancel booking	✅
Release seats after cancellation	✅
🧠 SOLID Principles
S — Single Responsibility Principle

Each class focuses on a specific responsibility.

For example:

PriceCalculator → Pricing
TicketPrinter   → Ticket output
BookingService  → Booking workflow
O — Open/Closed Principle

The payment system can be extended with new payment methods.

Payment
   ├── UpiPayment
   ├── CardPayment
   ├── CashPayment
   └── WalletPayment   ← Future
L — Liskov Substitution Principle

Concrete payment classes can be used through the Payment abstraction.

I — Interface Segregation Principle

The payment abstraction contains only the required payment operation.

D — Dependency Inversion Principle

The booking workflow works with the Payment abstraction rather than depending directly on one payment implementation.

🚧 Deliberate Scope Limitation

This project intentionally does not implement a real payment gateway.

UPI, Card, and Cash payments are simulated because the academic scope focuses on:

Object-oriented design, class relationships, booking workflow and SOLID principles.

🛠️ Tech Stack
Language        → C++
Standard        → C++17
Paradigm        → Object-Oriented Programming
Design          → Low-Level Design
Interface       → Console
Compiler        → Clang++
