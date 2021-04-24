#include <vector>
#include "Passenger.cpp"

// abstract class
class Transport {
public:
    string number;
    size_t seats;
    Driver *driver = NULL;
    vector<Passenger *> passengers;
    
    void info() {
        if (seats == 30)
            cout << "The bus №" << number;
        else if (seats == 4)
            cout << "The taxi №" << number;
        
        if (driver)
            cout << " has driver and ";
        else
            cout << " has no driver and ";
            
        if (passengers.size() < seats)
            cout << passengers.size() << " passengers.\n";
        else
            cout << " filled.\n";
    }
};

class Bus : public Transport {
public:
};

class Taxi : public Transport {
public:
    size_t childSeats;
};
