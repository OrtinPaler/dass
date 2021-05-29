#ifndef HYPHENS_H
#define HYPHENS_H

#include "abstract_interpreter.h"

// class for replacing the minus sign with a hyphen
class Hyphens : public AbstractInterpreter {
public:
    Hyphens(int);
    virtual void interpret(QString *context);
};

#endif // HYPHENS_H
