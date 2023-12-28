#ifndef SERVICE_H
#define SERVICE_H
#include <QDate>

class Service
{
private:
    int amount;
    QString type;
    float cost;
public:
    Service(int, QString, float);
    Service();
    int getAmount();
    float getCost();
    QString getType();
    void setType(QString);
    void setAmount(int);
    void setCost(float);
};
#endif // SERVICE_H

