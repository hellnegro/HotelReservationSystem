#include "room.h"

Room::Room(int roomNo, QString type, float price)
{
    this->roomNo = roomNo;
    this->type = type;
    this->price = price;
}

int Room::getRoomNo()
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
