#include "spaces.h"

Spaces::Spaces(int) :   AbstractInterpreter(1) {}

void Spaces::interpret(QString *context) {
    context->replace(QRegExp("[ ]+"), " ");
    context->replace(QRegExp("^[ ]"), "");
}
