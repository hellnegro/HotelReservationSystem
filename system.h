#ifndef SYSTEM_H
#define SYSTEM_H
#include "Reservation.h"
#include "service.h"
#include "Payment.h"

class System
{
public:
    System();
    void newReservation(Reservation reservation);
    void cancelReservation(Reservation reservation);
    void addService(Service service);
    void cancelService(Service service);
    void showDebt();
    void closeAccount();

private:
    QList<Reservation> reservations;
    QList<Service> services;
    QList<Payment> payments;

};

#endif // SYSTEM_H
