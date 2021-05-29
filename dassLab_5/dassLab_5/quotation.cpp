#include "quotation.h"

Quotation::Quotation(int) : AbstractInterpreter(1) {}

void Quotation::interpret(QString *context) {
    context->replace(QRegExp("(“)+"), "«");
    context->replace(QRegExp("(”)+"), "»");
    context->replace(QRegExp("(«)+"), "«");
    context->replace(QRegExp("(»)+"), "»");
    context->replace(QRegExp("(«\\s)"), "«");
    context->replace(QRegExp("(\\s»)"), "»");
}
