#include "hotel.h"

Hotel* Hotel::instance = nullptr;

Hotel *Hotel::getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}

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
    int i=0;
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
    QString name = query.value(0).toString();
    QString surname = query.value(1).toString();

    query.clear();
    //prepare transaction query
    query.prepare("INSERT INTO transaction (room, customerName, customerSurname) VALUES (:room, :customerName, :customerSurname)");
    query.bindValue(":room", roomNo);
    query.bindValue(":customerName", name);
    query.bindValue(":customerSurname", surname);

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
