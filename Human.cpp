#include "Human.h"

Human::Human(QString firstName, QString lastName, short age, QString gender)
    : firstName(firstName), lastName(lastName), age(age), gender(gender)
{
}

QString Human::getName() const
{
    return firstName;
}

QString Human::getSurname() const
{
    return lastName;
}

QString Human::getFullName() const
{
    return firstName + " " + lastName;
}

short Human::getAge() const
{
    return age;
}

QString Human::getGender() const
{
    return gender;
}
