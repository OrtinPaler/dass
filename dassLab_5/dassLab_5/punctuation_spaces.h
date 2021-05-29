#ifndef PUNCTUATIONSPACES_H
#define PUNCTUATIONSPACES_H

#include "abstract_interpreter.h"

// class for working with punctuation spaces
class PunctuationSpaces : public AbstractInterpreter {
public:
    PunctuationSpaces(int);
    virtual void interpret(QString *context);
};

#endif // PUNCTUATIONSPACES_H
