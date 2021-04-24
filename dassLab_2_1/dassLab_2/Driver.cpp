#include <iostream>
#include <string>
using namespace std;

// driver's license
enum License {
    B,
    D
};

// abstract class
class Driver {
public:
    string name;
    License license;
    
    virtual void info() {}
};

class DriverBus : public Driver {
public:
    virtual void info() {
        cout << "Bus driver " << name << ".\n";
    }
};

class DriverTaxi : public Driver {
public:
    virtual void info() {
        cout << "Taxi driver " << name << ".\n";
    }
};
