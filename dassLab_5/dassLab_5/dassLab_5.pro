QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstract_interpreter.cpp \
    foreign_chars.cpp \
    hyphens.cpp \
    line_translation.cpp \
    main.cpp \
    punctuations_paces.cpp \
    quotation.cpp \
    spaces.cpp \
    tabs.cpp \
    widget.cpp

HEADERS += \
    abstract_interpreter.h \
    foreign_chars.h \
    hyphens.h \
    line_translation.h \
    punctuation_spaces.h \
    quotation.h \
    spaces.h \
    tabs.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
