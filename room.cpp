/**
 * @class Room
 * @brief This class representing a room in the hotel management system.
 *
 * This class provides information about a room, including its number, type, and price.
 */


#include "room.h"

/**
     * @brief Constructor for the Room class.
     * @param roomNo The room number.
     * @param type The type of the room.
     * @param price The price of the room.
     */

Room::Room(int roomNo, QString type, float price)
{
    this->roomNo = roomNo;
    this->type = type;
    this->price = price;
}

/**
     * @brief Retrieves the room number.
     * @return Integer representing the room number.
     */

int Room::getRoomNo()
{
    return roomNo;
}

/**
     * @brief Retrieves the type of the room.
     * @return QString representing the room type.
     */

QString Room::getType()
{
    return type;
}


/**
     * @brief Retrieves the price of the room.
     * @return Float representing the room price.
     */

float Room::getPrice()
{
    return price;
}

/**
     * @brief Sets the price of the room.
     * @param price The new price for the room.
     */

void Room::setPrice(float price)
{
    this->price = price;
}
