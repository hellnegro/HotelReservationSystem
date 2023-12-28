#ifndef HOTEL_H
#define HOTEL_H

#include <QDebug>
#include "employee.h"
#include "service.h"
#include "room.h"

class Hotel
{
public:
    void newEmployee(Employee);
    void hireEmployee(Employee);
    void newService(Service);
    void deleteService(Service);
    static Hotel* getInstance();

private:
    Hotel(){};
    Hotel(Hotel const &){};
    static Hotel *instance;
    Employee *employee;
    Service *service;
    Room *room;
};

#endif // HOTEL_H
