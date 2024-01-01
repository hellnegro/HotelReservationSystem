#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDir>
#include <vector>
#include "Customer.h"
#include "employee.h"
#include "service.h"
#include "room.h"

class Hotel
{
public:
    static Hotel* instance;
    static Hotel* getInstance();
    void registerCustomer(Customer customer);
    void registerEmployee(Employee employee);
    std::vector<int> getRoomList(QString);
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
    QList<Employee> employees;
    QList<Service> services;
    QList<Room> rooms;
};

#endif // HOTEL_H
