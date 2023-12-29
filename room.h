#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room
{
public:
    Room(QString,QString,float);
    QString getTitle();
    QString getType();
    float getPrice();
    void setPrice(float);

private:

    QString title;
    QString type;
    float price;
};

#endif // ROOM_H
