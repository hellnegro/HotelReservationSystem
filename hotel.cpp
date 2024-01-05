/**
 * @class Hotel
 * @brief Represents the central entity managing hotel operations in the system.
 *
 * The Hotel class provides singleton access to hotel-related functionalities such as
 * customer and employee registration, room booking, check-out, and data retrieval.
 * It utilizes a SQLite database for data storage and retrieval.
 *
 * The class includes methods for registering customers and employees, retrieving lists of
 * available rooms and customer information, booking and checking out rooms, and managing
 * transactions within the hotel system.
 *
 * @note This class is a key component of the hotel management system, handling various
 * interactions and transactions within the application.
 */



#include "hotel.h"



/**
 * @brief Static instance of the Hotel class.
 */


Hotel* Hotel::instance = nullptr;


/**
 * @brief Gets the singleton instance of the Hotel class.
 * @return The singleton instance of the Hotel class.
 */

Hotel *Hotel::getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}

/**
 * @brief Registers a new customer in the system.
 * @param customer The customer object to be registered.
 * @return The ID of the registered customer.
 */

int Hotel::registerCustomer(Customer customer)
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db"));
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);

    query.prepare("INSERT INTO customer (name, surname, age, gender, phone, email,isBook) "
                  "VALUES (:name, :surname, :age, :gender, :phone, :email, :isBook)");
    query.bindValue(":name", customer.getName());
    query.bindValue(":surname", customer.getSurname());
    query.bindValue(":age", customer.getAge());
    query.bindValue(":gender", customer.getGender());
    query.bindValue(":phone", customer.getPhoneNumber());
    query.bindValue(":email", customer.getEmail());
    query.bindValue(":isBook", "n");

    QString customer_id;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        customer_id = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< customer_id;
    }
    query.clear();
    Database.close();
    return customer_id.toInt();
}
/**
 * @brief Registers a new employee in the system.
 * @param employee The employee object to be registered.
 * @return The ID of the registered employee.
 */

int Hotel::registerEmployee(Employee employee)
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db");
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);

    query.prepare("INSERT INTO employee (name, surname, age, gender, position) "
                  "VALUES (:name, :surname, :age, :gender, :position)");
    query.bindValue(":name", employee.getName());
    query.bindValue(":surname", employee.getSurname());
    query.bindValue(":age", employee.getAge());
    query.bindValue(":gender", employee.getGender());
    query.bindValue(":position", employee.getPosition());

    QString employee_id;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        employee_id = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< employee_id;
    }
    query.clear();
    Database.close();
    return employee_id.toInt();
}

/**
 * @brief Retrieves a list of available room numbers.
 * @param flag Filter flag for room availability ('y' for available, 'n' for booked).
 * @return A vector containing the available room numbers.
 */


std::vector<int> Hotel::getRoomList(QString flag = "y")
{
    std::vector<int> rooms;
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db");
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("SELECT roomNo FROM room WHERE available = '" + flag + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";

    while(query.next())
    {
        QString roomNo = query.value(0).toString();
        rooms.push_back(roomNo.toInt());

        qDebug()<<"Line is : "<<roomNo;
    }
    query.clear();
    Database.close();
    return rooms;
}

/**
 * @brief Retrieves a list of customer information based on booking status.
 * @param flag Filter flag for customer booking status ('y' for booked, 'n' for not booked).
 * @return A vector containing vectors of customer information (ID, name, surname).
 */


std::vector<std::vector<QString>> Hotel::getCustomerList(QString flag = "n")
{
    std::vector<std::vector<QString>> customers;
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db");
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("SELECT id, name, surname FROM customer WHERE isBook = '" + flag + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";

    while(query.next())
    {
        std::vector<QString> customer;
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString surname = query.value(2).toString();
        customer.push_back(id);
        customer.push_back(name);
        customer.push_back(surname);
        customers.push_back(customer);
        qDebug()<<"Line is : "<< id;
    }
    query.clear();
    Database.close();
    return customers;
}

/**
 * @brief Books a room for a customer, updating the database and creating a transaction.
 * @param roomNo The room number to be booked.
 * @param customerNo The customer ID for whom the room is booked.
 * @return The ID of the created transaction.
 */


int Hotel::bookRoom(int roomNo, int customerNo)
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db");
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);

    //prepare room query
    query.prepare("UPDATE room SET available ='n' WHERE roomNo ='" + QString::number(roomNo) + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();
    query.clear();

    //prepare customer query
    query.prepare("UPDATE customer SET isBook ='y' where id ='" + QString::number(customerNo)+ "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();
    query.clear();

    query.prepare("SELECT name, surname FROM customer WHERE id = '" + QString::number(customerNo) + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";
    QString name,surname;
    while(query.next())
    {
        name = query.value(0).toString();
        surname = query.value(1).toString();
    }
    qDebug() << name << surname;
    query.clear();

    //prepare transaction query
    query.prepare("INSERT INTO transaction (room, customerName, customerSurname, service, payment)"
                  "VALUES (:room, :customerName, :customerSurname, :service, :payment)");
    query.bindValue(":room", roomNo);
    query.bindValue(":customerName", name);
    query.bindValue(":customerSurname", surname);
    query.bindValue(":service", "0");
    query.bindValue(":payment", "0");

    QString transactionId;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        transactionId = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< transactionId;
    }
    query.clear();
    Database.close();
    return 0;
}

/**
 * @brief Checks out a customer, updating the room availability status in the database.
 * @param roomNo The room number to be checked out.
 * @return An integer indicating the success of the check-out operation.
 */


int Hotel::checkOut(int roomNo)
{
    qDebug()<<"in CheckOut for room no : " << roomNo;
    //**** update DB **********

    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db");
    if(QFile::exists(QString::fromStdString("C:/Users/bilgi/Documents/GitHub/HotelReservationSystem/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("UPDATE room SET available ='y' WHERE roomNo ='" + QString::number(roomNo) + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();
    query.clear();

    Database.close();
    return 0;
}
