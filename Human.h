#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

enum Gender { MALE, FEMALE };

class Human
{
private:

    QString firstName;
    QString lastName;
    short age;
    Gender gender;

public:
    Human(QString firstName, QString lastName, short age, Gender gender);
    Human();
    QString getName() const;
    QString getSurname() const;
    QString getFullName() const;
    short getAge() const;
    QString getGendertoString() const;

};

#endif // HUMAN_H
