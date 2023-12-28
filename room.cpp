#include "room.h"

Room::Room()
{
    title = "SELECT ROOM";
    type = "ROOM TYPE";
    price = 0.0;
}

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

/*    Room rooms[] = {{"101","SINGLE",150},
                    {"102","SINGLE",150},
                    {"103","SINGLE",150},
                    {"104","SINGLE",150},
                    {"105","SINGLE",150},
                    {"106","SINGLE",150},
                    {"201","DOUBLE",250},
                    {"202","DOUBLE",250},
                    {"203","DOUBLE",250},
                    {"301","SUIT",450},
                    {"301","SUIT",450}};
*/
