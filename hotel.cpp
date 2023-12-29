#include "hotel.h"

Hotel* Hotel::instance = nullptr;

Hotel *Hotel::getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
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

