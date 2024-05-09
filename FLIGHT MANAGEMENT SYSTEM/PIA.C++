#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Flight {
public:
    int flightNumber;
    string source;
    string destination;
    int departureTime;
    int arrivalTime;
    int duration;
    int availableSeats;

    void display() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Duration: " << duration << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    void saveToFile(ofstream& fout) {
        fout << flightNumber << "," << source << "," << destination << "," << departureTime << "," << arrivalTime << "," << duration << "," << availableSeats << endl;
    }

    void readFromFile(ifstream& input) {
        input >> flightNumber;
        input.ignore();
        getline(input, source, ',');
        getline(input, destination, ',');
        input >> departureTime; input.ignore();
        input >> arrivalTime; input.ignore();
        input >> duration; input.ignore();
        input >> availableSeats; input.ignore();
    }
};
class FlightManagementSystem {
public:
    Flight* flights;//array of flights using Flight class
    int numFlights;
    int maxFlights;

    FlightManagementSystem(int max,int no) 
    {
        maxFlights = max;
        flights = new Flight[maxFlights];//using dynamic memory allocation  
        numFlights = no;
    }
    ~FlightManagementSystem() 
    {
        delete[] flights; //deallocating memory 
    }
    int addFlight() 
    {
        if (numFlights > maxFlights)
        {
            cout << "Maximum Number of Flights Reached!" << endl;
            return 0;
        }
        else {
           Flight& newFlight= flights[numFlights] ;
            cout << "Enter Flight Number: ";
            cin >> newFlight.flightNumber;
            cout << "Enter Source: ";
            cin.ignore();
            getline(cin, newFlight.source);
            cout << "Enter Destination: ";
            getline(cin, newFlight.destination);
            cout << "Enter Departure Time: ";
            cin >> newFlight.departureTime;
            cout << "Enter Arrival Time: ";
            cin >> newFlight.arrivalTime;
            newFlight.duration = newFlight.arrivalTime - newFlight.departureTime;
            cout << "Enter Available Seats: ";
            cin >> newFlight.availableSeats;
            numFlights++;
            return 0;
        }
    }
    void displayAllFlights() 
    {
        for (int i = 0; i < numFlights; i++)
        {
            flights[i].display();
            cout << endl;
        }
    }
    void saveToFile(string fName) 
    {
        ofstream out.(fName);
        for (int i = 0; i < numFlights; i++) 
        {
            flights[i].saveToFile(out);
        }
     out.close();
    }
    void readFromFile(string fName) 
    {
        ifstream data;
        data.open(fName);
        Flight flight;
        while (!data.eof() && numFlights < maxFlights) {
            flight.readFromFile(data);
            flights[numFlights] = flight;
            numFlights++;
        }
        data.close();
    }

    void bookSeat() {
        int flightNumber;
        int numSeats;
        bool seat = false;
        cout << "Enter flight Number in which you are looking for seat : ";
        cin >> flightNumber;
        for (int i = 0; i < numFlights; i++) 
        {
                if (flights[i].flightNumber == flightNumber) 
                {
                    seat = true;
                    if (flights[i].availableSeats == 0)
                    {
                        cout << "Sorry, No Available Seats for this Flight!" << endl;
                    }
                    else {
                        cout << "Enter Number of Seats to Book: ";
                        cin >> numSeats;
                        if (numSeats > flights[i].availableSeats) {
                            cout << "Sorry, Not Enough Available Seats for this Flight!" << endl;
                        }
                        else {
                            flights[i].availableSeats -= numSeats;
                            cout << "Booking Confirmed!" << endl;
                        }
                    }
                    break;
                }
        }

        if (!seat)
        {
            cout << "Flight seat not found!" << endl;
        }
    }
};
int main()
{
    FlightManagementSystem PIA(10,0);
    

    int choice;
    PIA.readFromFile("AIRLINE FILE.txt");
    do {
        cout << endl;
        cout << "Flight Management System" << endl;
        cout << "0.Exit  " << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Display All Flights" << endl;
        cout << "3. Save to File" << endl;
        cout << "4. Load from File" << endl;
        cout << "5. Book Seat" << endl;
        cout << "6.PROJECT MEMBERS NAME " << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {    
        case 0:
            cout << "Exiting" << endl;
            break;
        case 1:
            PIA.addFlight();
            break;
        case 2:
            PIA.displayAllFlights();
            break;
        case 3:
            PIA.saveToFile("PIA_flights.txt");
            break;
        case 4:
            PIA.readFromFile("PIA_flights.txt");
            break;
        case 5:
            PIA.bookSeat();
            break;
        case 6:
            cout << " PROJECT CREATED BY \n1. ZAHEER AHMAD ABBASI " << endl
                << "2. HAMMAD YOUSAF" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } 
    while (choice != 0);
    return 0;
}

