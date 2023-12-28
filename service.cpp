#include "service.h"

Service::Service(int amount, QString type, float cost)
{
    this->amount = amount;
    this->type = type;
    this->cost = cost;
}

int Service::getAmount()
{
    return amount;
}

QString Service::getType()
{
    return type;
}

float Service::getCost()
{
    return cost;
}

void Service::setAmount(int amount)
{
    this->amount = amount;
}

void Service::setType(QString type)
{
    this->type = type;
}

void Service::setCost(float cost)
{
    this->cost = cost;
}
