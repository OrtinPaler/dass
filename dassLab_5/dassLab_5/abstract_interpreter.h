#ifndef ABSTRACTINTERPRETER_H
#define ABSTRACTINTERPRETER_H

#include <QRegExp>
#include <QString>

#include <iostream>

class AbstractInterpreter {
private:
    AbstractInterpreter *spaces;
    AbstractInterpreter *hyphens;
    AbstractInterpreter *tabs;
    AbstractInterpreter *carriagesReturn;
    AbstractInterpreter *quotation;
    AbstractInterpreter *pSpaces;
    AbstractInterpreter *fChars;
public:
    AbstractInterpreter();
    AbstractInterpreter(int);
    void virtual interpret(QString *context);
};

#endif // ABSTRACTINTERPRETER_H
