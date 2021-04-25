#include "Director.cpp"

void input(size_t &driverNum, size_t &passengerNum, size_t &transportNum) {
    cout << "Enter number of machines: ";
    cin >> transportNum;
    cout << "Enter number of passengers: ";
    cin >> passengerNum;
    cout << "Enter number of drivers: ";
    cin >> driverNum;
}

// further it is better to use the templates
vector<DriverBus *> createDrivers(Director *director, BuilderDriverBus *b_driver, size_t driverNum) {
    vector<DriverBus *> drivers;
    
    for (int i = 0; i < driverNum; i++) {
        director->makeDriver(b_driver);
        drivers.push_back(b_driver->getResult());
    }
    
    return drivers;
}

vector<DriverTaxi *> createDrivers(Director *director, BuilderDriverTaxi *b_driver, size_t driverNum) {
    vector<DriverTaxi *> drivers;
    
    for (int i = 0; i < driverNum; i++) {
        director->makeDriver(b_driver);
        drivers.push_back(b_driver->getResult());
    }
    
    return drivers;
}

vector<PassengerBus *> createPassengers(Director *director, BuilderPassengerBus *b_passenger, size_t passNum) {
    vector<PassengerBus *> passengers;
    
    for (int i = 0; i < passNum; i++) {
        director->makePassenger(b_passenger);
        passengers.push_back(b_passenger->getResult());
    }
    
    return passengers;
}

vector<PassengerTaxi *> createPassengers(Director *director, BuilderPassengerTaxi *b_passenger, size_t passNum) {
    vector<PassengerTaxi *> passengers;
    
    for (int i = 0; i < passNum; i++) {
        director->makePassenger(b_passenger);
        passengers.push_back(b_passenger->getResult());
    }
    
    return passengers;
}

vector<Bus *> createBuses(Director *director, BuilderBus *b_transport, size_t transportNum) {
    vector<Bus *> buses;
    
    for (int i = 0; i < transportNum; i++) {
        director->makeTransport(b_transport);
        buses.push_back(b_transport->getResult());
    }
    
    return buses;
}

vector<Taxi *> createTaxi(Director *director, BuilderTaxi *b_transport, size_t transportNum) {
    vector<Taxi *> taxi;

    for (int i = 0; i < transportNum; i++) {
        director->makeTransport(b_transport);
        taxi.push_back(b_transport->getResult());
    }
    
    return taxi;
}

void checkState(vector<Bus *> buses) {
    int a = 0;
    for (int i = 0; i < buses.size(); i++) {
        if (buses.at(a)->passengers.size() == 30 && buses.at(a)->driver != NULL) {
            cout << "The bus #" << buses.at(a)->number << " departs.\n";
            buses.erase(buses.begin() + a);
        }

        if (!buses.at(a)->driver) {
            if (buses.at(a)->passengers.size() < 30)
                cout << "The bus #" << buses.at(a)->number << " is waiting for passengers (" << (buses.at(a)->seats - buses.at(a)->passengers.size()) << " seats are available).\n";
            cout << "The bus #" << buses.at(a)->number << "is waiting for driver.\n";
            a++;
        }
        if (buses.at(a)->passengers.size() < 30) {
            cout << "The bus #" << buses.at(a)->number << " is waiting for passengers (" << (buses.at(a)->seats - buses.at(a)->passengers.size()) << " seats are available).\n";
            a++;
        }
    }
}

void checkState(vector<Taxi *> taxies) {
    int a = 0;
    for (int i = 0; i < taxies.size(); i++) {
        if (taxies.at(a)->passengers.size() == 4 && taxies.at(a)->driver != NULL) {
            cout << "The taxi #" << taxies.at(a)->number << " departs.\n";
            taxies.erase(taxies.begin() + a);
        }

        if (!taxies.at(a)->driver) {
            if (taxies.at(a)->passengers.size() < 4)
                cout << "The taxi #" << taxies.at(a)->number << " is waiting for passengers (" << (taxies.at(a)->seats - taxies.at(a)->passengers.size()) << " seats are available).\n";
            cout << "The taxi #" << taxies.at(a)->number << " is waiting for driver.\n";
            a++;
        }
        if (taxies.at(a)->passengers.size() < 4) {
            cout << "The taxi #" << taxies.at(a)->number << " is waiting for passengers (" << (taxies.at(a)->seats - taxies.at(a)->passengers.size()) << " seats are available).\n";
            if (!taxies.at(a)->driver)
                cout << "The taxi #" << taxies.at(a)->number << " is waiting for driver.\n";
            a++;
        }
    }
}

int main() {
    // added director
    Director *director = new Director;
    
    // added builders
    BuilderDriverBus *driver_builder = new BuilderDriverBus;
    BuilderPassengerBus *pass_builder = new BuilderPassengerBus;
    BuilderBus *bus = new BuilderBus;
    
    // install builders on director
    director->changeBuilderDriver(driver_builder);
    director->changeBuilderPassenger(pass_builder);
    director->changeBuilderTransport(bus);
    
    // enter data
    size_t driversOnBusesNum, passOnBusesNum, busesNum;
    input(driversOnBusesNum, passOnBusesNum, busesNum);
    
    // create data vectors
    vector<DriverBus *> driversOnBuses = createDrivers(director, driver_builder, driversOnBusesNum);
    vector<PassengerBus *> passOnBuses = createPassengers(director, pass_builder, passOnBusesNum);
    vector<Bus *> buses = createBuses(director, bus, busesNum);
    
    // added passengers in transport
    for (auto bus : buses)
        for (auto passenger : passOnBuses)
            if (bus->passengers.size() < 30) {
                bus->passengers.push_back(passenger);
                passOnBuses.erase(passOnBuses.begin());
            }
                
    // added drivers in transport
    for (auto bus : buses)
        for (auto driver : driversOnBuses)
            if (bus->driver == NULL) {
                bus->driver = driver;
                driversOnBuses.erase(driversOnBuses.begin());
            }
    
    // check state buses
    checkState(buses);

    // added builders
    BuilderDriverTaxi *driver_taxi_builder = new BuilderDriverTaxi;
    BuilderPassengerTaxi *pass_taxi_builder = new BuilderPassengerTaxi;
    BuilderTaxi *taxi = new BuilderTaxi;

    // install builders on director
    director->changeBuilderDriver(driver_taxi_builder);
    director->changeBuilderPassenger(pass_taxi_builder);
    director->changeBuilderTransport(taxi);

    // enter data
    cout << "\n#TAXI#\n";
    input(driversOnNum, passOnNum, Num);

    // create data vectors
    vector<DriverTaxi *> driversOnTaxies = createDrivers(director, driver_taxi_builder, driversOnNum);
    vector<PassengerTaxi *> passOnTaxies = createPassengers(director, pass_taxi_builder, passOnNum);
    vector<Taxi *> taxies = createTaxi(director, taxi, Num);

    // added passengers in transport
    for (auto taxi : taxies)
        for (auto passenger : passOnTaxies)
            if (taxi->passengers.size() < 4) {
                taxi->passengers.push_back(passenger);
                passOnTaxies.erase(passOnTaxies.begin());
            }

    // added drivers in transport
    for (auto taxi : taxies)
        for (auto driver : driversOnTaxies)
            if (taxi->driver == NULL) {
                taxi->driver = driver;
                driversOnTaxies.erase(driversOnTaxies.begin());
            }

    // check state buses
    checkState(taxies);
    
    return 0;
}
