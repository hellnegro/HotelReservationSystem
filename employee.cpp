#include "employee.h"

Employee::Employee(QString firstName, QString lastName, short age, QString gender, QString position)
    : Human(firstName, lastName, age, gender)
{
    this->position = position;
}

Employee::Employee(Human& human,QString position):Human(human)
{
    this->position = position;
}

QString Employee::getPosition()
{
    return position;
}

void Employee::setPosition(QString position)
{
    this->position = position;
}

QString Employee::getInfo()
{
    return Employee::getPosition() + " " + Employee::getFullName();
}

