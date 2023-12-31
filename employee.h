#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Human.h"

class Employee : public Human
{
private:
    int employeeNo;
    QString position;

public:
    Employee(QString, QString, short, QString, QString);
    Employee(Human&, QString);
    int getEmployeeNo();
    void setEmployeeNo(int);
    QString getPosition();
    void setPosition(QString);
    QString getInfo();
};

#endif // EMPLOYEE_H
