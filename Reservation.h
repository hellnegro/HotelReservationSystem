#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDate>
#include "Customer.h"
#include "Room.h"

class Reservation
{
public:
    Reservation(QList<Customer>, Room&);
    QList<Customer> getCustomer();
    Room getRoom();
    QDate getDate();
    void addCustomers(Customer);
    void removeCustomers(Customer);
    void addRoom(Room);
    void setRoom(Room);

private:
    QList<Customer> customers;
    Room* room;
    QDate date;
};

#endif // RESERVATION_H
