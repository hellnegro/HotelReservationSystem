#include "Reservation.h"


QList<Customer> Reservation::getCustomers()
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

void Reservation::addCustomer(Customer customer)
{
    customers.append(customer);
}

void Reservation::removeCustomer(Customer customer)
{/*
    QList<Customer>::iterator iter = customers.begin();
    while(iter != customers.end()){
        if((*iter).getCustomerNo() == customer.getCustomerNo())
            customers.erase(iter);
        iter++;
    }
*/
}

