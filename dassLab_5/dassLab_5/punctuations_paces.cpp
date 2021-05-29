#include "punctuation_spaces.h"

PunctuationSpaces::PunctuationSpaces(int)  : AbstractInterpreter(1) {}

void PunctuationSpaces::interpret(QString *context) {
    context->replace(QRegExp("(\\( )+"), "(");
    context->replace(QRegExp("( \\))+"), ")");
    context->replace(QRegExp("( ,)+"), ",");
    context->replace(QRegExp("( \\.)+"), ".");
    context->replace(QRegExp("( ;)+"), ";");
}
