#ifndef HOTEL_H
#define HOTEL_H

#include "system.h"
#include "employee.h"
#include "service.h"

class Hotel
{
public:
    ~Hotel();
    System getSystem();
    static Hotel* getInstance();
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
    Hotel(){};
    Hotel(Hotel const &){};
    static Hotel * instance;
    QList<Employee> employees;
    QList<Service> services;
    QList<Room> rooms;
    System *system;
};

#endif // HOTEL_H
