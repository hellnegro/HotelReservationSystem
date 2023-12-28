#include "hotel.h"

void Hotel::newEmployee(Employee employee)
{
    employees.append(employee);
}

void Hotel::hireEmployee(Employee employee)
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

