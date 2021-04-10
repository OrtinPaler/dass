#include "TransportElements.hpp"

TransportElements::~TransportElements(void) {
    for (auto passenger : passengers)
        delete passenger;

    for (auto transport : transports)
        delete transport;

    for (auto driver : drivers)
        delete driver;
}
