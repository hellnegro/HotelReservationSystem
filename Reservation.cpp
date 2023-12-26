#include "Reservation.h"

Reservation::Reservation(const std::string& title, const std::string& type, const QDate& date, const Room& room, const std::vector<Service>& services)
    : _title(title), _type(type), _date(date), _room(room), _services(services)
{
}

const std::string& Reservation::getTitle() const
{
    return _title;
}

const std::string& Reservation::getType() const
{
    return _type;
}

const QDate& Reservation::getDate() const
{
    return _date;
}

const Room& Reservation::getRoom() const
{
    return _room;
}

const std::vector<Service>& Reservation::getServices() const
{
    return _services;
}

void Reservation::setTitle(const std::string& title)
{
    _title = title;
}

void Reservation::setType(const std::string& type)
{
    _type = type;
}

void Reservation::setDate(const QDate& date)
{
    _date = date;
}

void Reservation::setRoom(const Room& room)
{
    _room = room;
}

void Reservation::addService(const Service& service)
{
    _services.push_back(service);
}

void Reservation::removeService(const Service& service)
{/*
    _services.erase(std::remove(_services.begin(), _services.end(), service), _services.end());
*/
}
