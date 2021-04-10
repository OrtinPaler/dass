#include "Driver.hpp"

Driver::Driver(void) {
    name = to_string(rand() % 100);
}

void Driver::info(void) {}

DriverBus::DriverBus(void) : Driver() {
    license = D;
}

void DriverBus::info(void) {
    cout << "Bus driver " << name << ".\n";
}

DriverTaxi::DriverTaxi(void) : Driver() {
    license = B;
}

void DriverTaxi::info(void) {
    cout << "Taxi driver " << name << ".\n";
}
