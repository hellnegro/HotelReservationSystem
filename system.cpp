
/**
 * @class System
 * @brief Coordinates functionalities within the hotel management system.
 *
 * The System class is responsible for handling reservations, services, customers, and other functionalities
 * within the hotel management system. It provides methods for creating and canceling reservations, managing
 * services, handling customer information, and more.
 *
 * @note Serving as a core component, this class ensures seamless interaction and coordination among
 * different aspects of the system.
 */

#include "system.h"

/**
 * @brief Adds a new reservation to the system.
 * @param reservation The reservation to be added.
 */

void System::newReservation(Reservation reservation)
{
    reservations.append(reservation);
}

/**
 * @brief Cancels a reservation in the system.
 * @param reservation The reservation to be canceled.
 */

void System::cancelReservation(Reservation reservation)
{
    QList<Reservation>::iterator iter = reservations.begin();
    while(iter != reservations.end()){
        if((*iter).getRoom().getRoomNo() == reservation.getRoom().getRoomNo())
            reservations.erase(iter);
        iter++;
    }
}


/**
 * @brief Adds a new service to the system.
 * @param service The service to be added.
 */

void System::addService(Service service)
{
    services.push_back(service);
}

/**
 * @brief Cancels a service in the system.
 * @param service The service to be canceled.
 */

void System::cancelService(Service service)
{
    QList<Service>::iterator iter = services.begin();
    while(iter != services.end()){
        if((*iter).getType() == service.getType())
            services.erase(iter);
        iter++;
    }
}

/**
 * @brief Retrieves the list of customers in the system.
 * @return The list of customers.
 */

QList<Customer> System::getCustomers()
{
    return customers;
}

/**
 * @brief Adds a new customer to the system.
 * @param customer The customer to be added.
 */

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

/**
 * @brief Displays the debt information in the system.
 */
void System::showDebt()
{

}

/**
 * @brief Closes the account in the system.
 */
void System::closeAccount()
{

}
