#ifndef SERVICE_H
#define SERVICE_H
#include <QDate>
#include <QDebug>

class Service
{
private:
    float cost;
    QString type;
    int amount;
public:
    Service(float, QString,int);
    float getCost();
    QString getType();
    int getAmount();
    void setCost(float);
    void setType(QString);
    void setAmount(int);

};
#endif // SERVICE_H

