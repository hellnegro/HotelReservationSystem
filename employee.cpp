#include "employee.h"

Employee::Employee(int employeeNo, QString firstName, QString lastName, short age, QString gender, QString position)
    : Human(firstName, lastName, age, gender)
{
    this->employeeNo = employeeNo;
    this->position = position;
}

Employee::Employee(int employeeNo, Human& human,QString position):Human(human)
{
    this->employeeNo = employeeNo;
    this->position = position;
}
int Employee::getEmployeeNo()
{
    return employeeNo;
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
    return "No"+ QString::number(employeeNo) + " " + Employee::getFullName()+ '\n' + Employee::getPosition();
}

