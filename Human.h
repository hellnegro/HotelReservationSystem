#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

class Human
{
private:

    QString firstName;
    QString lastName;
    short age;
    QString gender;

public:
    Human(QString firstName, QString lastName, short age, QString gender);
    QString getName() const;
    QString getSurname() const;
    QString getFullName() const;
    short getAge() const;
    QString getGender() const;
};

#endif // HUMAN_H
