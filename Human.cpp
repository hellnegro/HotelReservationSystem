#include "Human.h"

Human::Human(QString firstName, QString lastName, short age, Gender gender)
    : firstName(firstName), lastName(lastName), age(age), gender(gender)
{
}

Human::Human()
{
    firstName = "TYPE NAME";
    lastName = "TYPE SURNAME";
    age = 0;
    gender = Gender::MALE;
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

QString Human::getGendertoString() const
{
    return gender == Gender::MALE ? "MALE" : "FEMALE" ;
}
