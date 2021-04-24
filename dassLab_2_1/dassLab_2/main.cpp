#include "Director.cpp"

void input(size_t &driverNum, size_t &passengerNum, size_t &transportNum) {
    cout << "Enter number of machines: ";
    cin >> transportNum;
    cout << "Enter number of passengers: ";
    cin >> passengerNum;
    cout << "Enter number of drivers: ";
    cin >> driverNum;
}

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
    
    // TODO: read function void checkState(vector<Bus *> buses);
    
    return 0;
}

/*director->makeDriver(driver_builder);
director->makePassenger(pass_builder);
vector<Passenger *> passengers = { pass_builder->getResult() };
director->makeTransport(bus, driver_builder->getResult(), passengers);

bus->getResult()->info();
bus->getResult()->driver->info();
for (auto passenger : bus->getResult()->passengers)
    passenger->info();
cout << endl;

BuilderDriverTaxi *driver_taxi_builder = new BuilderDriverTaxi;
BuilderPassengerTaxi *pass_taxi_builder = new BuilderPassengerTaxi;
BuilderTaxi *taxi = new BuilderTaxi;

director->changeBuilderDriver(driver_taxi_builder);
director->changeBuilderPassenger(pass_taxi_builder);
director->changeBuilderTransport(taxi);

director->makeDriver(driver_taxi_builder);
director->makePassenger(pass_taxi_builder);
vector<Passenger *> passengers_taxi = { pass_taxi_builder->getResult() };
director->makeTransport(taxi, driver_taxi_builder->getResult(), passengers_taxi);

taxi->getResult()->info();
taxi->getResult()->driver->info();
for (auto passenger : taxi->getResult()->passengers)
    passenger->info();
cout << endl;*/
