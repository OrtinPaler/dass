#include "line_translation.h"

LineTranslation::LineTranslation(int) : AbstractInterpreter(1) {}

void LineTranslation::interpret(QString *context) {
    context->replace(QRegExp("\n+"), "\n");
}
