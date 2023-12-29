#include "hotel.h"


QList<Employee> Hotel::getEmployees()
{
    return employees;
}

QList<Service> Hotel::getServices()
{
    return services;
}

QList<Room> Hotel::getRooms()
{
    return rooms;
}

void Hotel::setEmployees(QList<Employee> emp)
{
    employees = emp;
}

void Hotel::setServices(QList<Service> serv)
{
    services = serv;
}

void Hotel::setRooms(QList<Room> room)
{
    rooms = room;
}

void Hotel::newEmployee(Employee employee)
{
    employees.append(employee);
}

void Hotel::firingEmployee(Employee employee)
{
    QList<Employee>::iterator iter = employees.begin();
    while(iter != employees.end()){
        if((*iter).getEmployeeNo() == employee.getEmployeeNo())
            employees.erase(iter);
        iter++;
    }
}

void  Hotel::newService(Service service)
{
    services.append(service);
}

void  Hotel::deleteService(Service service)
{
    QList<Service>::iterator iter = services.begin();
    while(iter != services.end()){
        if((*iter).getType() == service.getType())
            services.erase(iter);
        iter++;
    }
}
