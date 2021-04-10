#ifndef Driver_hpp
#define Driver_hpp

#include <iostream>
#include <string>
using namespace std;

enum License {
    B,
    D
};

// abstract class
class Driver {
public:
    string name;
    License license;
    
    Driver(void);
    virtual void info(void);
};

class DriverBus : public Driver {
public:
    DriverBus(void);
    virtual void info(void);
};

class DriverTaxi : public Driver {
public:
    DriverTaxi(void);
    virtual void info(void);
};

#endif /* Driver_hpp */
