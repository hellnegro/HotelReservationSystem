#ifndef SYSTEM_H
#define SYSTEM_H
#include "Reservation.h"
#include "service.h"
#include "Payment.h"
#include "Customer.h"

class System
{
public:
    System(){};
    void newReservation(Reservation reservation);
    void cancelReservation(Reservation reservation);
    void addService(Service service);
    void cancelService(Service service);
    QList<Customer> getCustomers();
    void addCustomers(Customer customer);
    void removeCustomer(Customer customer);
    void showDebt();
    void closeAccount();

private:
    QList<Reservation> reservations;
    QList<Service> services;
    QList<Payment> payments;
    QList<Customer> customers;
};

#endif // SYSTEM_H
