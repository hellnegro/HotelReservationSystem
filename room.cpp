#include "room.h"

Room::Room(QString roomNo, QString type, float price)
{
    this->roomNo = roomNo;
    this->type = type;
    this->price = price;
}

QString Room::getTitle()
{
    return roomNo;
}

QString Room::getType()
{
    return type;
}

float Room::getPrice()
{
    return price;
}

void Room::setPrice(float price)
{
    this->price = price;
}
