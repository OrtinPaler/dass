#ifndef Transport_hpp
#define Transport_hpp

#include <vector>
#include "Driver.hpp"
#include "Passenger.hpp"

// abstract class
class Transport {
public:
    string number;
    size_t seats;
    Driver *driver = NULL;
    vector<Passenger *> *passengers = NULL;
    
    Transport(void);
    ~Transport(void);
    void info();
};

class Bus : public Transport {
public:
    Bus(void);
    ~Bus(void);
};

class Taxi : public Transport {
public:
    size_t childSeats;
    
    Taxi(void);
    ~Taxi(void);
};

#endif /* Transport_hpp */
