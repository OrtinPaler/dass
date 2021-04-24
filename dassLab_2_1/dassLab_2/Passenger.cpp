#include <cstdlib>
#include <ctime>
#include "Driver.cpp"

// abstract class
class Passenger {
public:
    string name;
    size_t age;
    
    virtual void info() {}
};

class PassengerBus : public Passenger {
public:
    virtual void info() {
        cout << "Bus passenger " << name << ".\n";
    }
};

class PassengerTaxi : public Passenger {
public:
    virtual void info() {
        cout << "Taxi passenger " << name << ".\n";
    }
};
