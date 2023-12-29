#ifndef HOTEL_H
#define HOTEL_H

#include "employee.h"
#include "service.h"
#include "room.h"

class Hotel
{
public:
    static Hotel* getInstance();
    void newEmployee(Employee);
    void firingEmployee(Employee);
    void newService(Service);
    void deleteService(Service);

private:
    static Hotel* instance;
    QList<Employee> employees;
    QList<Service> services;
    QList<Room> rooms;
};

#endif // HOTEL_H
