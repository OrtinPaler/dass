#ifndef TransportElements_hpp
#define TransportElements_hpp

#include "Driver.hpp"
#include "Passenger.hpp"
#include "Transport.hpp"

class TransportElements {
public:
    vector<Passenger *> passengers;
    vector<Transport *> transports;
    vector<Driver *> drivers;
    
    ~TransportElements(void);
};

#endif /* TransportElements_hpp */
