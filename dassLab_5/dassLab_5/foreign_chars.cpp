#include "foreign_chars.h"

ForeignChars::ForeignChars(int) : AbstractInterpreter(1) {}

void ForeignChars::interpret(QString *context) {
    context->replace(QRegExp("а+"), "а");
    context->replace(QRegExp("с+"), "с");
    context->replace(QRegExp("В+"), "В");
    context->replace(QRegExp("Н+"), "Н");
}
