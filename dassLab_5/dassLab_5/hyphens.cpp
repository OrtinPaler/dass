#include "hyphens.h"

Hyphens::Hyphens(int)  : AbstractInterpreter(1) {}

void Hyphens::interpret(QString *context) {
    context->replace(QRegExp(" - +"), " — ");
}
