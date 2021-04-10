#include "Transport.hpp"

Transport::Transport(void) {
    number = to_string(rand() % 100);
    passengers = new vector<Passenger *>;
}

Transport::~Transport(void) {
    if (!passengers)
        for (auto passenger : *passengers)
            delete passenger;
    if (!driver)
        delete driver;
}

void Transport::info() {
    if (seats == 30)
        cout << "The bus №" << number;
    else if (seats == 4)
        cout << "The taxi №" << number;
    
    if (!driver)
        cout << " has driver and ";
    else
        cout << " has no driver and ";
    
    if (passengers->size() < seats)
        cout << passengers->size() << " passengers.\n";
    else
        cout << " filled.\n";
}

Bus::Bus(void) : Transport() {
    seats = 30;
    driver = new DriverBus;
}

Bus::~Bus(void) {
    if (!passengers)
        for (auto passenger : *passengers)
            delete passenger;
    if (!driver)
        delete driver;
}

Taxi::Taxi(void) : Transport() {
    seats = 4;
    childSeats = 0;
    driver = new DriverTaxi;
}

Taxi::~Taxi(void) {
    if (!passengers)
        for (auto passenger : *passengers)
            delete passenger;
    if (!driver)
        delete driver;
}
