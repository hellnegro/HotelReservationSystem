#include "Customer.h"

Customer::Customer(QString firstName, QString lastName, short age, QString gender, QString phoneNumber, QString email)
    : Human(firstName, lastName, age, gender)
{
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Customer::Customer(Human& human, QString phoneNumber, QString email):Human(human)
{
    this->phoneNumber = phoneNumber;
    this->email = email;
}


QString Customer::getPhoneNumber() const
{
    return phoneNumber;
}

QString Customer::getEmail() const
{
    return email;
}

void Customer::setPhoneNumber(QString phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Customer::setEmail(QString email)
{
    this->email = email;
}

QString Customer::getInfo()
{
    return  Customer::getFullName();
}
