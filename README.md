# 🧠 G. SOLID Principles & Design Decisions

The system applies object-oriented design principles and demonstrates
the following SOLID principles.

## Single Responsibility Principle (SRP)

Each major class has a focused responsibility.

| Class | Responsibility |
|---|---|
| `Movie` | Stores movie information |
| `Show` | Stores show information |
| `ShowSeat` | Maintains seat status for a show |
| `PriceCalculator` | Calculates ticket price |
| `TicketPrinter` | Prints ticket details |
| `BookingService` | Manages booking operations |

This avoids putting all system logic into a single class.

---

## Open/Closed Principle (OCP)

The payment system is designed so that new payment methods can be
added without changing the existing payment abstraction.

```text
             Payment
                │
       ┌────────┼────────┐
       ↓        ↓        ↓
     UPI      Card      Cash
