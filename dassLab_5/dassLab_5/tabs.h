#ifndef TABS_H
#define TABS_H

#include "abstract_interpreter.h"

// class for working with tabs
class Tabs : public AbstractInterpreter {
public:
    Tabs(int);
    virtual void interpret(QString *context);
};

#endif // TABS_H
