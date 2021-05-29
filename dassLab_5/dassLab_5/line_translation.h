#ifndef CARRIAGESRETURN_H
#define CARRIAGESRETURN_H

#include "abstract_interpreter.h"

// class for line translation (instead of \n\n\n returns \n)
class LineTranslation : public AbstractInterpreter {
public:
    LineTranslation(int);
    virtual void interpret(QString *context);
};

#endif // CARRIAGESRETURN_H
