
# Flight Management System

This project implements a Flight Management System in C++. It allows users to manage flights, book seats, and save flight data to files. Here's a breakdown of the features and functionalities:

## Features:

1. **Flight Management:** Users can add new flights, display all flights, and book seats on available flights.

2. **Data Persistence:** Flight data can be saved to and loaded from files for persistent storage.

3. **Dynamic Memory Allocation:** Flights are managed using dynamic memory allocation to handle a variable number of flights.

4. **Basic Flight Information:** Each flight consists of the following information:
   - Flight Number
   - Source
   - Destination
   - Departure Time
   - Arrival Time
   - Duration
   - Available Seats

5. **Seat Booking:** Users can book seats on available flights. The system checks for seat availability and confirms bookings accordingly.

6. **Project Information:** The project also includes information about the project creators.

## Usage:

1. **Add Flight (Option 1):** Users can add a new flight by entering relevant information such as flight number, source, destination, departure time, arrival time, and available seats.

2. **Display All Flights (Option 2):** Users can view details of all flights currently in the system.

3. **Save to File (Option 3):** Flight data can be saved to a file for future reference.

4. **Load from File (Option 4):** Previously saved flight data can be loaded from a file into the system.

5. **Book Seat (Option 5):** Users can book seats on available flights by specifying the flight number and the number of seats to book.

6. **Exit (Option 0):** Users can exit the system.

## Project Members:
- Zaheer Ahmad Abbasi

## File Handling:
Flight data can be saved to and loaded from a file named "PIA_flights.txt" in the current directory.

## Note:
- The system supports a maximum of 10 flights.
- When booking seats, the system checks for seat availability and confirms bookings if seats are available.

