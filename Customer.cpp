#include "Customer.h"

Customer::Customer(QString firstName, QString lastName, short age, QString gender, QString phoneNumber, QString email)
    : Human(firstName, lastName, age, gender)
{
    customerNo = 0;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Customer::Customer(Human& human, QString phoneNumber, QString email):Human(human)
{
    customerNo = 0;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

int Customer::getCustomerNo()
{
    return customerNo;
}

void Customer::setCustomerNo(int no)
{
    customerNo = no;
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
