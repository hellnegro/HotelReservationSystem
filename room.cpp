#include "room.h"

Room::Room()
{

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

bool Room::clean()
{
    if(isEmpty)
        isClean = true;
    return isClean;
}
