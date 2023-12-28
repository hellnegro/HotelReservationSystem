#include "system.h"

System::System()
{
}

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

void System::showDebt()
{

}
void System::closeAccount()
{

}
