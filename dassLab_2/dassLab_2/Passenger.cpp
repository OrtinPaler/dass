#include "Passenger.hpp"

void Passenger::info(void) {}

PassengerBus::PassengerBus() {
    name = to_string(rand() % 100);
    age = rand() % 151;
}

void PassengerBus::info(void) {
    cout << "Bus passenger " << name << ".\n";
}

PassengerTaxi::PassengerTaxi() {
    name = to_string(rand() % 100);
    age = rand() % 151;
}

void PassengerTaxi::info(void) {
    cout << "Taxi passenger " << name << ".\n";
}
