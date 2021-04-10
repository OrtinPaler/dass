#ifndef Passenger_hpp
#define Passenger_hpp

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// abstract class
class Passenger {
public:
    string name;
    size_t age;

    virtual void info(void);
};

class PassengerBus : public Passenger {
public:
    PassengerBus();
    virtual void info(void);
};


class PassengerTaxi : public Passenger {
public:
    PassengerTaxi();
    virtual void info(void);
};

#endif /* Passenger_hpp */
