#include "Builder.hpp"

Builder::Builder(void) : te(NULL) {}

Builder::~Builder(void) {
    delete te;
}
void Builder::createTE(void) {
    te = new TransportElements;
}

void Builder::buildPassenger(void) {}
void Builder::buildDriver(void) {}
void Builder::buildTransport(void) {}

TransportElements *Builder::getResult(void) {
    return te;
}

void BuilderBus::buildPassenger(void) {
    te->passengers.push_back(new PassengerBus);
}

void BuilderBus::buildDriver(void) {
    te->drivers.push_back(new DriverBus);
}

void BuilderBus::buildTransport(void) {
    te->transports.push_back(new Bus);
}

void BuilderTaxi::buildPassenger(void) {
    te->passengers.push_back(new PassengerTaxi);
}

void BuilderTaxi::buildDriver(void) {
    te->drivers.push_back(new DriverTaxi);
}

void BuilderTaxi::buildTransport(void) {
    te->transports.push_back(new Taxi);
}
