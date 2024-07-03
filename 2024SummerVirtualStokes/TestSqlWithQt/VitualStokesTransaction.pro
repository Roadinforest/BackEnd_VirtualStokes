QT       += core gui sql
QT       += charts
QT       += sql

CONFIG += console
CONFIG -= app_bundle

#win32:QMAKE_LFLAGS += -shared


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
   backdb.cpp \
   backendwithdatabase2.cpp \
   chartspline.cpp \
    main.cpp \
    mainwindow.cpp \
   portfolio.cpp \
   record.cpp \
   stock.cpp \
   user.cpp \
   virtualcurrency.cpp


HEADERS += \
   backdb.h \
   backendwithdatabase2.h \
   chartspline.h \
    mainwindow.h \
   portfolio.h \
   record.h \
   stock.h \
   user.h \
   virtualcurrency.h


FORMS += \
   chartspline.ui \
    mainwindow.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DEPENDPATH += 'C:/Program Files/MySQL/MySQL Server 8.0/include'


# For linking MySQL library on Windows
win32: LIBS += -llibmysql

win32: LIBS += -L'C:/Program Files/MySQL/MySQL Server 8.0/lib/' -lmysqlclient

INCLUDEPATH += 'C:/Program Files/MySQL/MySQL Server 8.0/include'
DEPENDPATH += 'C:/Program Files/MySQL/MySQL Server 8.0/include'
