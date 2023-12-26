QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    Human.cpp \
    Payment.cpp \
    Reservation.cpp \
    availability.cpp \
    booktheroom.cpp \
    homepage.cpp \
    loginpage.cpp \
    main.cpp \
    paymentpage.cpp \
    registration.cpp \
    service.cpp

HEADERS += \
    Customer.h \
    Human.h \
    Payment.h \
    Reservation.h \
    availability.h \
    booktheroom.h \
    homepage.h \
    loginpage.h \
    paymentpage.h \
    registration.h \
    service.h

FORMS += \
    availability.ui \
    booktheroom.ui \
    homepage.ui \
    loginpage.ui \
    paymentpage.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
