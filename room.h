#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QDebug>

class Room
{
public:
    Room();
    QString getTitle();
    QString getType();
    float getPrice();
    void setPrice(float);
    bool clean();

private:
    QString title;
    QString type;
    float price;
    bool isClean = true;
    bool isEmpty = true;
};

#endif // ROOM_H
