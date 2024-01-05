/**
 * @class Payment
 * @brief Manages payment transactions within the hotel management system.
 *
 * The Payment class stores information about a payment transaction, including the
 * amount of debt, payment method, and transaction date. It provides methods to retrieve
 * these details.
 *
 * @note This class is used to manage and record payment transactions within the system.
 */



#include "Payment.h"


/**
 * @brief Constructor for the Payment class.
 * @param debt The amount of debt to be paid.
 * @param method The payment method used for the transaction.
 */


Payment::Payment(float debt, QString method)
{
    this->debt = debt;
    this->method = method;
    date = QDate::currentDate().toString("dd.MM.yyyy");
}

/**
 * @brief Gets the amount of debt in the payment transaction.
 * @return The amount of debt.
 */

float Payment::getDebt()
{
    return debt;
}

/**
 * @brief Gets the payment method used for the transaction.
 * @return The payment method.
 */

QString Payment::getMethod()
{
    return method;
}

/**
 * @brief Gets the date of the payment transaction.
 * @return The transaction date in the format "dd.MM.yyyy".
 */

QString Payment::getDate()
{
    return date;
}

