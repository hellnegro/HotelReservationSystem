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
#include "room.h"

class Hotel
{
public:
    static Hotel* instance;
    static Hotel* getInstance();
    int registerCustomer(Customer);
    int registerEmployee(Employee);
    std::vector<int> getRoomList(QString);
    std::vector<std::vector<QString>> getCustomerList(QString);
    int bookRoom(int,int);
    int checkOut(int roomNo);

private:
    Hotel(){};
    Hotel(Hotel const &){};
    std::vector<int> rooms;
    std::vector<int> customers;
};

#endif // HOTEL_H
