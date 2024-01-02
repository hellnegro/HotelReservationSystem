#include "hotel.h"

Hotel* Hotel::instance = nullptr;

Hotel *Hotel::getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}

void Hotel::registerCustomer(Customer customer)
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

    query.prepare("INSERT INTO customer (name, surname, age, gender, phone, email) "
                  "VALUES (:name, :surname, :age, :gender, :phone, :email)");
    query.bindValue(":name", customer.getName());
    query.bindValue(":surname", customer.getSurname());
    query.bindValue(":age", customer.getAge());
    query.bindValue(":gender", customer.getGender());
    query.bindValue(":phone", customer.getPhoneNumber());
    query.bindValue(":email", customer.getEmail());

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
}

void Hotel::registerEmployee(Employee employee)
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

std::vector<QString> Hotel::getCustomerList(QString flag = "n")
{
    std::vector<QString> customers;
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
    query.prepare("SELECT name, surname FROM customer WHERE isBook = '" + flag + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";
    int i=0;
    while(query.next())
    {
        QString name = query.value(i).toString();
        QString surname = query.value(++i).toString();
        QString fullName = name.append(" ").append(surname);
        customers.push_back(fullName);

        qDebug()<<"Line is : "<< fullName;
    }
    query.clear();
    Database.close();
    return customers;
}

int Hotel::bookRoom(int roomNo, QString customer)
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
    query.prepare("UPDATE room SET available ='n' WHERE roomNo ='" +QString::number(roomNo)+ "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();

    query.clear();

    //prepare room query
    query.prepare("SELECT * FROM room WHERE roomNo = '" + QString::number(roomNo) + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";
    int room_id = query.lastQuery().toInt();
    query.clear();


    //prepare customer query    
    QString name = customer.split("\t").at(0);
    QString surname = customer.split("\t").at(1);
    query.prepare("SELECT * FROM customer WHERE name = '" + name + "," + surname + "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";
    int cusmoter_id = query.lastQuery().toInt();
    query.clear();

    query.prepare("UPDATE customer SET isBook ='y' where id ='" +QString::number(cusmoter_id)+ "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();
    query.clear();


    query.prepare("INSERT INTO transaction (room, customer) VALUES (:room, :customer)");
    query.bindValue(":room", room_id);
    query.bindValue(":customer", cusmoter_id);

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
