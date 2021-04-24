sD#include "Transport.cpp"

// abstract class
class BuilderDriver {
public:
    virtual void reset() {}
    virtual void setName() {}
    virtual void setLicense() {}
};

class BuilderDriverBus : public BuilderDriver {
private:
    DriverBus *db;
public:
    virtual void reset() {
        db = new DriverBus;
    }
    
    virtual void setName() {
        db->name = to_string(rand() % 100); // just rand name
    }
    
    virtual void setLicense() {
        db->license = D;
    }
    
    DriverBus *getResult() {
        return db;
    }
};

class BuilderDriverTaxi : public BuilderDriver {
private:
    DriverTaxi *dt;
public:
    virtual void reset() {
        dt = new DriverTaxi;
    }
    
    virtual void setName() {
        dt->name = to_string(101 + rand() % 200); // just rand name
    }
    
    virtual void setLicense() {
        dt->license = B;
    }
    
    DriverTaxi *getResult() {
        return dt;
    }
};

// abstract class
class BuilderPassenger {
public:
    virtual void reset() {}
    virtual void setName() {}
    virtual void setAge() {}
};

class BuilderPassengerBus : public BuilderPassenger {
private:
    PassengerBus *pb;
public:
    virtual void reset() {
        pb = new PassengerBus;
    }
    
    virtual void setName() {
        pb->name = to_string(rand() % 100); // just rand name
    }
    
    virtual void setAge() {
        pb->age = rand() % 151; // suppose people live less than 151 years
    }
    
    PassengerBus *getResult() {
        return pb;
    }
};

class BuilderPassengerTaxi : public BuilderPassenger {
private:
    PassengerTaxi *pt;
public:
    virtual void reset() {
        pt = new PassengerTaxi;
    }
    
    virtual void setName() {
        pt->name = to_string(101 + rand() % 200); // just rand name
    }
    
    virtual void setAge() {
        pt->age = rand() % 151; // suppose people live less than 151 years
    }
    
    PassengerTaxi *getResult() {
        return pt;
    }
};

// abstract class
class BuilderTransport {
public:
    virtual void reset() {}
    virtual void setNumber() {}
    virtual void setSeats() {}
};

class BuilderBus : public BuilderTransport {
private:
    Bus *bus;
public:
    virtual void reset() {
        bus = new Bus;
    }
    
    virtual void setNumber() {
        bus->number = to_string(rand() % 100);   // just rand number
    }
    
    virtual void setSeats() {
        bus->seats = 30;
    }
    
    Bus *getResult() {
        return bus;
    }
};

class BuilderTaxi : public BuilderTransport {
private:
    Taxi *taxi;
public:
    virtual void reset() {
        taxi = new Taxi;
    }
    
    virtual void setNumber() {
        taxi->number = to_string(rand() % 100);   // just rand number
    }
    
    virtual void setSeats() {
        taxi->seats = 4;
    }
    
    Taxi *getResult() {
        return taxi;
    }
};
