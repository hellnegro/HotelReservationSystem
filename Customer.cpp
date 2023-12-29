#include "Customer.h"

Customer::Customer(int customerNo, QString firstName, QString lastName, short age, QString gender, QString phoneNumber, QString email)
    : Human(firstName, lastName, age, gender)
{
    this->customerNo = customerNo;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Customer::Customer(int customerNo, Human& human, QString phoneNumber, QString email):Human(human)
{
    this->customerNo = customerNo;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

int Customer::getCustomerNo() const
{
    return customerNo;
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
    return "No"+ QString::number(customerNo) + " " + Customer::getFullName();
}
