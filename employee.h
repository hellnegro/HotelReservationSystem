#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Human.h"

class Employee : public Human
{
private:
    int employeeNo;
    QString position;

public:
    Employee(int,QString, QString, short, QString, QString);
    Employee(int,Human&, QString);
    int getEmployeeNo();
    QString getPosition();
    void setPosition(QString);
    QString getInfo();
};

#endif // EMPLOYEE_H
