#include "Payment.h"

Payment::Payment(float debt, QString method)
{
    this->debt = debt;
    this->method = method;
    date = QDate::currentDate().toString("dd.MM.yyyy");
}

Payment::Payment()
{
    debt = 0.0;
    method = "CASH";
    date = QDate::currentDate().toString("dd.MM.yyyy");
}

float Payment::getDebt()
{
    return debt;
}

QString Payment::getMethod()
{
    return method;
}

QString Payment::getDate()
{
    return date;
}

