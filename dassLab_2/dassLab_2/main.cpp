#include "Director.hpp"

void input(int *transportNum, int *peopleNum, int *driverNum) {
    cout << "Enter number of machines: ";
    cin >> *transportNum;
    cout << "Enter number of passengers: ";
    cin >> *peopleNum;
    cout << "Enter number of drivers: ";
    cin >> *driverNum;
}

int boarding(TransportElements &elem) {
    cout << "Now free " << elem.transports.size() << " machines.\n";

    for (auto transport : elem.transports) {
        int i = 0;
        for (auto passenger : elem.passengers) {
            transport->passengers->push_back(passenger);
            elem.passengers.erase(elem.passengers.begin());
            if (++i == transport->seats)
                break;
        }

        if (!transport->driver) {
            if (elem.drivers.size() != 0) {
                transport->driver = elem.drivers[0];
                elem.drivers.erase(elem.drivers.begin());
            }
            else {
                cout << "There is no drivers.\n";
            }
        }

        if (transport->driver && (transport->passengers->size() == transport->seats)) {
            cout << "The machine " << transport->number << " is ready to go.\n";
            delete transport;
            elem.transports.erase(elem.transports.begin());
        }
    }

    if (elem.transports.size() == 0) {
        cout << "All machines is filled.\n";
        return 0;
    } else {
        cout << "Unfilled transport:\n";
        for (auto transport : elem.transports)
            cout << "Transport number " << transport->number << " has "
            << (transport->seats - transport->passengers->size()) << " seats and "
            << ((transport->driver) ? "has driver.\n" : "hasn't driver.\n");

        cout << "Unplaced passengers: " << elem.passengers.size() << endl;
        cout << "Unplaced drivers: " << elem.drivers.size() << endl;
        return 0;
    }
}

int main(void) {
    srand(static_cast<unsigned int>(time(0)));
    
    Director dir;
    BuilderBus busBuilder;
    BuilderTaxi taxiBuilder;
    
    TransportElements *busElements = dir.createTE(busBuilder);
    TransportElements *taxiElements = dir.createTE(taxiBuilder);
    
    cout << "Bus:\n";
    boarding(*busElements);
    
    cout << "\nTaxi:\n";
    boarding(*taxiElements);
    
    return 0;
}
