/**
 * @class Employee
 * @brief Models a staff member in the hotel, characterized by a specific role and responsibilities.
 *
 * The Employee class inherits from the Human class and adds specific
 * attributes for managing employee information, such as position.
 * It provides constructors for creating employee objects with various parameters,
 * getter and setter methods for accessing and modifying employee attributes,
 * and a method to retrieve employee information including position and full name.
 */

#include "employee.h"

/**
 * @brief Constructor for creating an Employee object with specified attributes.
 * @param firstName The first name of the employee.
 * @param lastName The last name of the employee.
 * @param age The age of the employee.
 * @param gender The gender of the employee.
 * @param position The position of the employee.
 */

Employee::Employee(QString firstName, QString lastName, short age, QString gender, QString position)
    : Human(firstName, lastName, age, gender)
{
    employeeNo = 0;
    this->position = position;
}

/**
 * @brief Constructor for creating an Employee object using existing Human attributes.
 * @param human The Human object to initialize the Employee.
 * @param position The position of the employee.
 */

Employee::Employee(Human& human,QString position):Human(human)
{
    employeeNo = 0;
    this->position = position;
}

/**
 * @brief Gets the employee number.
 * @return The employee number.
 */

int Employee::getEmployeeNo()
{
    return employeeNo;
}

/**
 * @brief Sets the employee number.
 * @param no The employee number to be set.
 */

void Employee::setEmployeeNo(int no)
{
    employeeNo = no;
}

/**
 * @brief Gets the position of the employee.
 * @return The position.
 */

QString Employee::getPosition()
{
    return position;
}



/**
 * @brief Sets the position of the employee.
 * @param position The position to be set.
 */

void Employee::setPosition(QString position)
{
    this->position = position;
}

/**
 * @brief Gets the information of the employee, including position and full name.
 * @return The information of the employee.
 */


QString Employee::getInfo()
{
    return Employee::getPosition() + " " + Employee::getFullName();
}

