#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Human.h"
class Customer : public Human
{
private:
    int customerNo;
    QString phoneNumber;
    QString email;

public:
    Customer(int, QString, QString, short, QString, QString, QString);
    Customer(int, Human&, QString, QString);
    int getCustomerNo() const;
    QString getPhoneNumber() const;
    QString getEmail() const;
    void setPhoneNumber(QString);
    void setEmail(QString);
};

#endif // CUSTOMER_H

