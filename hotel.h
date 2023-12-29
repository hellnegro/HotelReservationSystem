#ifndef HOTEL_H
#define HOTEL_H

#include "employee.h"
#include "service.h"
#include "room.h"

class Hotel
{
public:
    QList<Employee> getEmployees();
    QList<Service> getServices();
    QList<Room> getRooms();
    void setEmployees(QList<Employee>);
    void setServices(QList<Service>);
    void setRooms(QList<Room>);
    void newEmployee(Employee);
    void firingEmployee(Employee);
    void newService(Service);
    void deleteService(Service);


private:
    QList<Employee> employees;
    QList<Service> services;
    QList<Room> rooms;
};

#endif // HOTEL_H
