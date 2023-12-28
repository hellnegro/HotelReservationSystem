#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDate>

class Payment
{
private:
    float debt;
    QString method;
    QString date;
public:
    Payment(float,QString);
    Payment();
    float getDebt();
    QString getMethod();
    QString getDate();
};

#endif // PAYMENT_H

