#include "Customer.h"

Customer::Customer(int customerNo, QString firstName, QString lastName, short age, Gender gender, QString phoneNumber, QString email)
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

Customer::Customer():Human()
{
    customerNo=0;
    phoneNumber="505 0000 123";
    email = "abc@example.com";
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
