#ifndef Builder_hpp
#define Builder_hpp

#include "TransportElements.hpp"

// abstract class
class Builder {
protected:
    TransportElements *te;
    
public:
    Builder(void);
    ~Builder(void);
    virtual void createTE(void);
    virtual void buildPassenger(void);
    virtual void buildDriver(void);
    virtual void buildTransport(void);
    virtual TransportElements *getResult();
};

class BuilderBus : public Builder {
public:
    virtual void buildPassenger(void);
    virtual void buildDriver(void);
    virtual void buildTransport(void);
};

class BuilderTaxi : public Builder {
public:
    virtual void buildPassenger(void);
    virtual void buildDriver(void);
    virtual void buildTransport(void);
};

#endif /* Builder_hpp */
