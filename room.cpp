#include "room.h"

Room::Room(QString title, QString type, float price)
{
    this->title = title;
    this->type = type;
    this->price = price;
}

QString Room::getTitle()
{
    return title;
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
