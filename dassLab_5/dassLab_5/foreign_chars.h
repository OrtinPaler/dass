#ifndef FOREIGNCHARS_H
#define FOREIGNCHARS_H

#include "abstract_interpreter.h"

// class for replacing similar foreign characters with Russian
class ForeignChars : public AbstractInterpreter {
public:
    ForeignChars(int);
    virtual void interpret(QString *context);
};

#endif // FOREIGNCHARS_H
