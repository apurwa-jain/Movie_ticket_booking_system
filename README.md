# Movie Ticket Booking System

A modular, console-based movie ticket booking system developed in C++.

## Features

- Display movies, languages, durations, and show timings
- Display cinema screens and seat layouts
- Book available seats for a selected show
- Support Silver, Gold, and Platinum seat categories
- Calculate booking prices based on seat category
- Support UPI, card, and cash payment options
- Print a booking ticket after successful payment
- Cancel bookings and release booked seats
- View booking details and handle invalid input safely

## How to Compile and Run

The project uses one `.cpp` file per class and includes the implementation
files through `main.cpp`. Compile `main.cpp` only:

```bash
g++ -std=c++17 main.cpp -o movie_booking
./movie_booking
```

On Windows:

```bash
g++ -std=c++17 main.cpp -o movie_booking.exe
movie_booking.exe
```

The executable is not committed to GitHub because it is a generated build
file. Build it locally from the source code.

## Project Structure

| File | Responsibility |
|---|---|
| `01_Movie.cpp` | Movie information |
| `02_Seat.cpp` | Seat details and category |
| `03_Screen.cpp` | Screen and seats |
| `04_Cinema.cpp` | Cinema and screens |
| `05_Show.cpp` | Movie show and timing |
| `06_ShowSeat.cpp` | Seat status for a show |
| `07_Customer.cpp` | Customer information |
| `08_Booking.cpp` | Booking details |
| `09_Payment.cpp` | Payment abstraction |
| `10_PaymentTypes.cpp` | Payment method implementations |
| `11_PriceCalculator.cpp` | Price calculation |
| `12_TicketPrinter.cpp` | Ticket output |
| `13_BookingService.cpp` | Booking workflow |
| `main.cpp` | Program entry point |

## OOP Concepts Demonstrated

- **Encapsulation:** Classes protect their data through private members and
  public methods.
- **Abstraction:** Payment behavior is defined through a common interface.
- **Inheritance:** Different payment types share the payment abstraction.
- **Polymorphism:** The selected payment method is resolved at runtime.
- **Composition:** A cinema contains screens, and screens contain seats.
- **Association:** Shows use movie and screen objects to represent bookings.

## Documentation

Project reports and design diagrams are available in the [`docs`](docs)
folder:

- [MBS report](docs/MBS_report.pdf)
- [MBS output](docs/MBS_output.pdf)
- [Class diagram](docs/class_diagram.jpeg)
- [Sequence diagram](docs/sequence_diagram.png)
