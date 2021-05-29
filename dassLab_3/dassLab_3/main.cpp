#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class AirlineUser {
public:
    AirlineUser() {}
    virtual ~AirlineUser() {}
    virtual int getLuggageWeight() = 0;
};

class Passenger : public AirlineUser {
private:
    int luggageWeight;

public:
    Passenger() {
        luggageWeight  = rand() % 56 + 5;
    }

    virtual ~Passenger() {}

    virtual int getLuggageWeight() {
        return luggageWeight;
    }
};

class Pilot : public AirlineUser {
public:
    Pilot() {}
    virtual ~Pilot() {}

    virtual int getLuggageWeight() {
        return 0;
    }
};

class Stewardess : public AirlineUser {
public:
    Stewardess() {}
    virtual ~Stewardess() {}

    virtual int getLuggageWeight() {
        return 0;
    }
};

class PassengerСlass : public AirlineUser {
protected:
    vector<AirlineUser *> users;

public:
    PassengerСlass() {}

    void addUser(AirlineUser *user) {
        users.push_back(user);
    }

    virtual int getLuggageWeight() {
        int totalWeight = 0;
        for (AirlineUser *user : users)
            totalWeight += user->getLuggageWeight();
        return totalWeight;
    }

    size_t getUsersSize() {
        return users.size();
    }

    ~PassengerСlass() {
        for (AirlineUser *user : users)
            delete user;
    }
};

class First : public PassengerСlass {
public:
    First() {}
};

class Buisness : public PassengerСlass {
private:
    int freeLuggage = 35;

public:
    Buisness() {}
};

class Economy : public PassengerСlass {
private:
    int freeLuggage = 20;
    
public:
    Economy() {}

    void removedLuggage(int needToRemoveNum) {
        int luggage = 0;
        int i = 0;

        while (luggage < needToRemoveNum) {
            luggage += users[i]->getLuggageWeight();
            cout << "  User " << i << " have " << users[i]->getLuggageWeight() << endl;
            i++;
        }
    }
};

class Plane : public PassengerСlass {
public:
    Plane() {}

    size_t getFirstClassSize() {
        for (int i = 0; i < users.size(); i++) {
            First *_class = dynamic_cast<First *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getUsersSize();
        }
        return 0;
    }

    size_t getBuisnessClassSize() {
        for (int i = 0; i < users.size(); i++) {
            Buisness *_class = dynamic_cast<Buisness *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getUsersSize();
        }
        return 0;
    }

    size_t getEconomyClassSize() {
        for (int i = 0; i < users.size(); i++) {
            Economy *_class = dynamic_cast<Economy *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getUsersSize();
        }
        return 0;
    }

    size_t getPilotsSize() {
        size_t count = 0;
        for (int i = 0; i < users.size(); i++) {
            Pilot *pilot = dynamic_cast<Pilot *>((AirlineUser *)users[i]);
            if (pilot)
                count++;
        }
        return count;
    }

    size_t getStuwardessesSize() {
        size_t count = 0;
        for (int i = 0; i < users.size(); i++) {
            Stewardess *stewardess = dynamic_cast<Stewardess *>((AirlineUser *)users[i]);
            if (stewardess)
                count++;
        }
        return count;
    }

    int getFirstLuggageWeight() {
        for (int i = 0; i < users.size(); i++) {
            First *_class = dynamic_cast<First *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getLuggageWeight();
        }
        return 0;
    }

    int getBuisnessLuggageWeight() {
        for (int i = 0; i < users.size(); i++) {
            Buisness *_class = dynamic_cast<Buisness *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getLuggageWeight();
        }
        return 0;
    }

    int getEconomyLuggageWeight() {
        for (int i = 0; i < users.size(); i++) {
            Economy *_class = dynamic_cast<Economy *>((AirlineUser *)users[i]);
            if (_class)
                return _class->getLuggageWeight();
        }
        return 0;
    }

    void infoAboutRemovedLuggage(int luggage) {
        for (int i = 0; i < users.size(); i++) {
            Economy *_class = dynamic_cast<Economy *>((AirlineUser *)users[i]);
            if (_class)
                _class->removedLuggage(luggage);
        }
    }
};

class AirlineCompany {
private:
    int maxWeight = 0;

    vector<Stewardess *> stewardesses;
    vector<Pilot *> pilots;

    vector<First *> firstPassengers;
    vector<Buisness *> buisnessPassengers;
    vector<Economy *> economyPassengers;

    vector<Plane *> planes;

public:
    AirlineCompany(int maxWeight) : maxWeight(maxWeight) {}

    ~AirlineCompany() {
        for (Stewardess *stewardess : stewardesses)
            delete stewardess;

        for (Pilot *pilot : pilots)
            delete pilot;

        for (First *passenger : firstPassengers)
            delete passenger;

        for (Buisness *passenger : buisnessPassengers)
            delete passenger;

        for (Economy *passenger : economyPassengers)
            delete passenger;

        for (Plane *plane : planes)
            delete plane;
    }
    
    void setMaxWeight(int _maxWeight) {
        maxWeight = _maxWeight;
    }

    void addPlanes(int size) {
        for (int i = 0; i < size; i++)
            planes.push_back(new Plane());
    }

    // add staff
    void addStewardesses(int size) {
        for (int i = 0; i < size; i++)
            stewardesses.push_back(new Stewardess());
    }

    void addPilots(int size) {
        for (int i = 0; i < size; i++)
            pilots.push_back(new Pilot());
    }

    // add passengers
    void addFirstPassengers() {
        First *passenger = new First();
        for (int i = 0; i < 10; i++)
            passenger->addUser(new Passenger());
        firstPassengers.push_back(passenger);
    }

    void addBuisnessPassengers() {
        Buisness *passenger = new Buisness();
        for (int i = 0; i < 20; i++)
            passenger->addUser(new Passenger());
        buisnessPassengers.push_back(passenger);
    }

    void addEconomyPassengers() {
        Economy *passenger = new Economy();
        for (int i = 0; i < 150; i++)
            passenger->addUser(new Passenger());
        economyPassengers.push_back(passenger);
    }

    // fill the airline with data
    void fillAirlineData(int *planesSize, int *stewSize, int *pilotsSize, int *firstSize, int *buisSize, int *ecoSize) {
        addPlanes(*planesSize);
        addStewardesses(*stewSize);
        addPilots(*pilotsSize);
        for (int i = 0; i < *firstSize; i++)
            addFirstPassengers();
        for (int i = 0; i < *buisSize; i++)
            addBuisnessPassengers();
        for (int i = 0; i < *ecoSize; i++)
            addEconomyPassengers();
    }

    void fillPlanes() {
        for (int j = 0; j < planes.size(); j++) {
            size_t pilotsSize = planes[j]->getPilotsSize();
            for (int i = 0; i < 2 - pilotsSize; i++)
                if (pilots.size()) {
                    planes[j]->addUser(pilots.front());
                    pilots.erase(pilots.begin());
                }

            size_t stuwardessesSize = planes[j]->getStuwardessesSize();
            for (int i = 0; i < 6 - stuwardessesSize; i++)
                if (stewardesses.size()) {
                    planes[j]->addUser(stewardesses.front());
                    stewardesses.erase(stewardesses.begin());
                }
            
            if (!planes[j]->getFirstClassSize())
                if (firstPassengers.size()) {
                    planes[j]->addUser((AirlineUser *)firstPassengers.front());
                    firstPassengers.erase(firstPassengers.begin());
                }

            if (!planes[j]->getBuisnessClassSize())
                if (buisnessPassengers.size()) {
                    planes[j]->addUser((AirlineUser *)buisnessPassengers.front());
                    buisnessPassengers.erase(buisnessPassengers.begin());
                }

            if (!planes[j]->getEconomyClassSize())
                if (economyPassengers.size()) {
                    planes[j]->addUser((AirlineUser *)economyPassengers.front());
                    economyPassengers.erase(economyPassengers.begin());
                }
        }
    }

    void showPlain() {
        for (int i = 0; i < planes.size(); i++) {
            cout << "\nAIRCOMPANY INFO\nPlane " << i << ":\n";

            int totalWeight = planes[i]->getLuggageWeight();
            size_t firstSize = planes[i]->getFirstClassSize();
            size_t buisnessSize = planes[i]->getBuisnessClassSize();
            size_t economySize = planes[i]->getEconomyClassSize();
            size_t pilotsSize = planes[i]->getPilotsSize();
            size_t stuwardessesSize = planes[i]->getStuwardessesSize();

            cout << "Total weight: " << totalWeight << endl;

            if (buisnessSize && economySize && firstSize && (pilotsSize == 2) && (stuwardessesSize == 6) && (totalWeight <= maxWeight))
                cout << "Status: READY\n";
            else {
                cout << "Status: NOT READY\n\nMESSAGE:\n";

                cout << " Pilots: " << pilotsSize << endl;
                cout << " Stuwardesses: "<< stuwardessesSize << endl;
                
                if (totalWeight > maxWeight)
                    cout << " Total weight: " << totalWeight << " out of " << maxWeight << "\n";

                if (firstSize)
                    cout << "  First class baggage weight: " << planes[i]->getFirstLuggageWeight() << " out of +oo\n";
                else
                    cout << "  First class baggage weight: 0 out of +oo\n";
                
                if (buisnessSize)
                    cout << "  Buisness class baggage weight: " << planes[i]->getBuisnessLuggageWeight() << " out of 700\n";
                else
                    cout << "  Buisness class baggage weight: 0 out of 700\n";

                if (economySize != 0)
                    cout << "  Economy class baggage weight: " << planes[i]->getEconomyLuggageWeight() << " out of 3000\n";
                else
                    cout << "  Economy class baggage weight: 0 out of 3000\n";

                int lug = planes[i]->getEconomyLuggageWeight();
                if (totalWeight > maxWeight)
                    if ((totalWeight - lug) < maxWeight) {
                        cout << "\nWARNING!\n Whose baggage will be removed:\n";
                        planes[i]->infoAboutRemovedLuggage(totalWeight - maxWeight);
                    }
            }
            cout << endl << endl;
        }
    }
};

void input(int *planesSize, int *stewSize, int *pilotsSize, int *firstSize, int *buisSize, int *ecoSize) {
    cout << "\nINPUT DATA\n Planes: ";
    cin >> *planesSize;
    cout << " Pilots: ";
    cin >> *pilotsSize;
    cout << " Stewardesses: ";
    cin >> *stewSize;
    cout << " Passengers:\n"
    << "  first class: ";
    cin >> *firstSize;
    cout << "  buisness class: ";
    cin >> *buisSize;
    cout << "  economy class: ";
    cin >> *ecoSize;
    cout << endl;
}

int main() {
    srand((int)time(NULL));
    
    AirlineCompany acompany(5700);
    int planesSize, stewSize, pilotsSize, firstSize, buisSize, ecoSize;
    
    int ans;
    bool exit = true;
    while(exit) {
        cout << "1. Start boarding\n"
            << "2. Input data\n"
            << "3. Exit\n\n"
            << "user % ";
        cin >> ans;

        switch (ans) {
            case 1: {
                acompany.fillPlanes();
                acompany.showPlain();
                break;
            }
                
            case 2: {
                input(&planesSize, &stewSize, &pilotsSize, &firstSize, &buisSize, &ecoSize);
                acompany.fillAirlineData(&planesSize, &stewSize, &pilotsSize, &firstSize, &buisSize, &ecoSize);
                break;
            }
                
            default: {
                exit = false;
                break;
            }
        }
    }
}
