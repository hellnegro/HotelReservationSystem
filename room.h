#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room
{
public:
    Room(int,QString,float);
    int getRoomNo();
    QString getType();
    float getPrice();
    void setPrice(float);

private:

    int roomNo;
    QString type;
    float price;
};

#endif // ROOM_H
