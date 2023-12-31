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
    Customer(QString, QString, short, QString, QString, QString);
    Customer(Human&, QString, QString);
    int getCustomerNo();
    void setCustomerNo(int);
    QString getPhoneNumber() const;
    QString getEmail() const;
    void setPhoneNumber(QString);
    void setEmail(QString);
    QString getInfo();
};

#endif // CUSTOMER_H

