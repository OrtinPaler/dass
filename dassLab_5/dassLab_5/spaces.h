#ifndef SPACES_H
#define SPACES_H

#include "abstract_interpreter.h"

// class for working with spaces
class Spaces : public AbstractInterpreter {
public:
    Spaces(int);
    virtual void interpret(QString *context);
};

#endif // SPACES_H
