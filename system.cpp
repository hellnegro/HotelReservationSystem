#include "system.h"

void System::newReservation(Reservation reservation)
{
    reservations.append(reservation);
}

void System::cancelReservation(Reservation reservation)
{
    QList<Reservation>::iterator iter = reservations.begin();
    while(iter != reservations.end()){
        if((*iter).getRoom().getTitle() == reservation.getRoom().getTitle())
            reservations.erase(iter);
        iter++;
    }
}

void System::addService(Service service)
{
    services.push_back(service);
}

void System::cancelService(Service service)
{
    QList<Service>::iterator iter = services.begin();
    while(iter != services.end()){
        if((*iter).getType() == service.getType())
            services.erase(iter);
        iter++;
    }
}

QList<Customer> System::getCustomers()
{
    return customers;
}

void System::addCustomers(Customer customer)
{
    customers.push_back(customer);
}

void System::removeCustomer(Customer customer)
{/*
    QList<Customer>::iterator iter = customers.begin();
    while(iter != customers.end()){
        if((*iter).getCustomerNo() == customer.getCustomerNo())
            customers.erase(iter);
        iter++;
    }
*/
}

void System::showDebt()
{

}
void System::closeAccount()
{

}
