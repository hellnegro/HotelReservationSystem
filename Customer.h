#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDebug>

#include "Human.h"

class Customer : public Human
{

private:

    QString phoneNumber;
    QString email;

public:

    Customer(QString firstName, QString lastName, short age, Gender gender, QString phoneNumber, QString email);

    QString getPhoneNumber() const;
    QString getEmail() const;

    void setPhoneNumber(QString phoneNumber);
    void setEmail(QString email);

};

#endif // CUSTOMER_H

