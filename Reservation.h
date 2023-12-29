#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDate>
#include "Customer.h"
#include "Room.h"

class Reservation
{
public:
    QList<Customer> getCustomers();
    Room getRoom();
    QDate getDate();
    void addCustomer(Customer);
    void removeCustomer(Customer);
    void addRoom(Room);
    void setRoom(Room);

private:
    QList<Customer> customers;
    Room room;
    QDate date;
};

#endif // RESERVATION_H
