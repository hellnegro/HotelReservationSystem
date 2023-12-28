#include "Reservation.h"

Reservation::Reservation(QList<Customer> customers, Room& room)
{
    this->customers = customers;
    this->room = room;
    this->date = QDate::currentDate();
}

Reservation::Reservation()
{
    Customer customer = Customer();
    customers.append(customer);
    date = QDate::currentDate();
}

QList<Customer> Reservation::getCustomer()
{
    return customers;
}

Room Reservation::getRoom()
{
    return room;
}

QDate Reservation::getDate()
{
    return date;
}

void Reservation::addCustomers(Customer customer)
{
    customers.append(customer);
}

void Reservation::removeCustomers(Customer customer)
{
    QList<Customer>::iterator iter = customers.begin();
    while(iter != customers.end()){
        if((*iter).getCustomerNo() == customer.getCustomerNo())
            customers.erase(iter);
        iter++;
    }
}

