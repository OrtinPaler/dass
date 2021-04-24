#include "Builder.cpp"

class Director {
public:
    BuilderDriver *bd = NULL;
    BuilderPassenger *bp = NULL;
    BuilderTransport *bt = NULL;
    
    void changeBuilderDriver(BuilderDriver *_bd) {
        bd = _bd;
    }
    
    void changeBuilderPassenger(BuilderPassenger *_bp) {
        bp = _bp;
    }
    
    void changeBuilderTransport(BuilderTransport *_bt) {
        bt = _bt;
    }
    
    void makeDriver(BuilderDriver *_bd) {
        _bd->reset();
        _bd->setName();
        _bd->setLicense();
    }
    
    void makePassenger(BuilderPassenger *_bp) {
        _bp->reset();
        _bp->setName();
        _bp->setAge();
    }
    
    void makeTransport(BuilderTransport *_bt) {
        _bt->reset();
        _bt->setNumber();
        _bt->setSeats();
    }
};
