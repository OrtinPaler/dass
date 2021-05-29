#include "tabs.h"

Tabs::Tabs(int) :  AbstractInterpreter(1) {}

void Tabs::interpret(QString *context) {
    context->replace(QRegExp("( \t)+"), "\t");
    context->replace(QRegExp("(\t )+"), "\t");
    context->replace(QRegExp("\t+"), "\t");
}
