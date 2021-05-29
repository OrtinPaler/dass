#ifndef QUOTATION_H
#define QUOTATION_H

#include "abstract_interpreter.h"

// class for replacing quotes
class Quotation : public AbstractInterpreter {
public:
    Quotation(int);
    virtual void interpret(QString *context);
};

#endif // QUOTATION_H
