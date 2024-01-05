/**
 * @class Customer
 * @brief Represents a customer in the hotel management system.
 *
 * The Customer class inherits from the Human class and adds specific
 * attributes for managing customer information, such as phone number and email.
 * It provides constructors for creating customer objects with various parameters,
 * getter and setter methods for accessing and modifying customer attributes,
 * and a method to retrieve customer's full name.
 */


#include "Customer.h"


/**
 * @brief Constructor for creating a Customer object with specified attributes.
 * @param firstName The first name of the customer.
 * @param lastName The last name of the customer.
 * @param age The age of the customer.
 * @param gender The gender of the customer.
 * @param phoneNumber The phone number of the customer.
 * @param email The email address of the customer.
 */



Customer::Customer(QString firstName, QString lastName, short age, QString gender, QString phoneNumber, QString email)
    : Human(firstName, lastName, age, gender)
{
    customerNo = 0;
    this->phoneNumber = phoneNumber;
    this->email = email;
}
/**
 * @brief Constructor for creating a Customer object using existing Human attributes.
 * @param human The Human object to initialize the Customer.
 * @param phoneNumber The phone number of the customer.
 * @param email The email address of the customer.
 */
Customer::Customer(Human& human, QString phoneNumber, QString email):Human(human)
{
    customerNo = 0;
    this->phoneNumber = phoneNumber;
    this->email = email;
}
/**
 * @brief Gets the customer number.
 * @return The customer number.
 */
int Customer::getCustomerNo()
{
    return customerNo;
}

/**
 * @brief Sets the customer number.
 * @param no The customer number to be set.
 */



void Customer::setCustomerNo(int no)
{
    customerNo = no;
}



/**
 * @brief Gets the phone number of the customer.
 * @return The phone number.
 */


QString Customer::getPhoneNumber() const
{
    return phoneNumber;
}


/**
 * @brief Gets the email address of the customer.
 * @return The email address.
 */



QString Customer::getEmail() const
{
    return email;
}


/**
 * @brief Sets the phone number of the customer.
 * @param phoneNumber The phone number to be set.
 */



void Customer::setPhoneNumber(QString phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

/**
 * @brief Sets the email address of the customer.
 * @param email The email address to be set.
 */


void Customer::setEmail(QString email)
{
    this->email = email;
}

/**
 * @brief Gets the information of the customer, including the full name.
 * @return The information of the customer.
 */

QString Customer::getInfo()
{
    return  Customer::getFullName();
}
