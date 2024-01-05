
/**
 * @class Human
 * @brief Defines a foundational human entity within the hotel management system.
 *
 * The Human class serves as a base class for more specialized entities such as
 * customers and employees. It provides common attributes and methods related to
 * personal information, including name, age, and gender.
 *
 * @note This class is designed to be inherited by more specific human entities in the system.
 */


#include "Human.h"

/**
 * @brief Constructor for creating a Human object with specified attributes.
 * @param firstName The first name of the human.
 * @param lastName The last name of the human.
 * @param age The age of the human.
 * @param gender The gender of the human.
 */

Human::Human(QString firstName, QString lastName, short age, QString gender)
    : firstName(firstName), lastName(lastName), age(age), gender(gender)
{
}

/**
 * @brief Gets the first name of the human.
 * @return The first name.
 */

QString Human::getName() const
{
    return firstName;
}


/**
 * @brief Gets the last name of the human.
 * @return The last name.
 */

QString Human::getSurname() const
{
    return lastName;
}

/**
 * @brief Gets the full name of the human.
 * @return The full name (concatenation of first name and last name).
 */

QString Human::getFullName() const
{
    return firstName + " " + lastName;
}

/**
 * @brief Gets the age of the human.
 * @return The age.
 */

short Human::getAge() const
{
    return age;
}

/**
 * @brief Gets the gender of the human.
 * @return The gender.
 */

QString Human::getGender() const
{
    return gender;
}
