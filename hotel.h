#ifndef HOTEL_H
#define HOTEL_H

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

private:
    QList<Employee> employees;
    QList<Service> services;
    QList<Room> rooms;
};

#endif // HOTEL_H
