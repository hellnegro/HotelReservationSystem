/**
 * @class Reservation
 * @brief Handles the user interface for registering new customers or employees in the hotel management system.
 *
 * The Registration class provides an interface for users to register as customers or employees.
 * Users can input their personal information, and based on the selected status, the system
 * registers them as customers or employees.
 *
 * @note This class efficiently handles the registration process within the hotel management system.
 */


#include "Reservation.h"

/**
     * @brief Retrieves the list of customers associated with the reservation.
     * @return List of customers.
     */

QList<Customer> Reservation::getCustomers()
{
    return customers;
}

/**
     * @brief Retrieves the room associated with the reservation.
     * @return Room object.
     */

Room Reservation::getRoom()
{
    return room;
}

/**
 * @brief Retrieves the date of the reservation.
 * @return QString representing the reservation date in the format "dd.MM.yyyy".
 */

QDate Reservation::getDate()
{
    return date;
}

/**
     * @brief Adds a customer to the reservation.
     * @param customer Customer object to be added.
     */

void Reservation::addCustomer(Customer customer)
{
    customers.append(customer);
}

/**
     * @brief Removes a customer from the reservation.
     * @param customer Customer object to be removed.
     */
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

