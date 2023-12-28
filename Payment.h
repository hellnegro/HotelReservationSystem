#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDate>
#include <QDebug>

class Payment
{
private:
    float debt;
    QString method;
    QDate date;
public:
    Payment(float,QString);
    float getDebt();
    QString getMethod();
    QString getDate();
};

#endif // PAYMENT_H

