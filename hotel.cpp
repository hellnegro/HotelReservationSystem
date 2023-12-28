#include "hotel.h"

Hotel* Hotel::instance = nullptr;

void newEmployee(Employee)
{

}

void hireEmployee(Employee)
{

}

void newService(Service)
{

}

void deleteService(Service)
{

}

Hotel *Hotel::getInstance()
{
    qDebug()<<"Hotel class is created!";
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}
