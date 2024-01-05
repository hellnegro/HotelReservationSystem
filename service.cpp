/**
 * @class Service
 * @brief Manages information about a service offered in the hotel management system.
 *
 * The Service class encapsulates information about a specific service, including
 * the amount, type, and cost. It provides methods to retrieve and modify these details.
 *
 * @note This class plays a crucial role in maintaining and tracking the different services provided.
 */



#include "service.h"


/**
 * @brief Constructor for the Service class.
 * @param amount The quantity or amount of the service.
 * @param type The type or category of the service.
 * @param cost The cost associated with the service.
 */

Service::Service(int amount, QString type, float cost)
{
    this->amount = amount;
    this->type = type;
    this->cost = cost;
}

/**
 * @brief Gets the quantity or amount of the service.
 * @return The service amount.
 */

int Service::getAmount()
{
    return amount;
}

/**
 * @brief Gets the type or category of the service.
 * @return The service type.
 */

QString Service::getType()
{
    return type;
}

/**
 * @brief Gets the cost associated with the service.
 * @return The service cost.
 */

float Service::getCost()
{
    return cost;
}

/**
 * @brief Sets the quantity or amount of the service.
 * @param amount The new service amount to be set.
 */

void Service::setAmount(int amount)
{
    this->amount = amount;
}

/**
 * @brief Sets the type or category of the service.
 * @param type The new service type to be set.
 */

void Service::setType(QString type)
{
    this->type = type;
}


/**
 * @brief Sets the cost associated with the service.
 * @param cost The new service cost to be set.
 */

void Service::setCost(float cost)
{
    this->cost = cost;
}
