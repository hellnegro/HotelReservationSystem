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

    query.prepare("INSERT INTO customer (name, surname, age, gender, phone, email) VALUES ('"
                + customer.getName() + "','" + customer.getSurname() + "','" + customer.getAge() + "','"
                + customer.getGender() + "','" + customer.getPhoneNumber() + "','"
                + customer.getEmail() + "')");

    QString customer_id;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        customer_id = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< customer_id;
    }
    Database.close();
}

void Hotel::registerEmployee(Employee employee)
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

    query.prepare("INSERT INTO employee (name, surname, age, gender, position) VALUES ('"
                  + employee.getName() + "','" + employee.getSurname() + "','" + employee.getAge() + "','"
                  + employee.getGender() + "','" + employee.getPosition() + "')");
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
    Database.setDatabaseName(QString::fromStdString(":/resource/database/hotel.db"));
    if(QFile::exists(QString::fromStdString(":/resource/database/hotel.db")))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("select number from room where available = '" + flag + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";

    while(query.next())
    {
        QString record = query.value(0).toString();
        rooms.push_back(record.toInt());
        qDebug()<<"Line is : "<<record;
    }

    Database.close();
    return rooms;
}

QList<Employee> Hotel::getEmployees()
{
    return employees;
}

QList<Service> Hotel::getServices()
{
    return services;
}

QList<Room> Hotel::getRooms()
{
    return rooms;
}

void Hotel::setEmployees(QList<Employee> emp)
{
    employees = emp;
}

void Hotel::setServices(QList<Service> serv)
{
    services = serv;
}

void Hotel::setRooms(QList<Room> room)
{
    rooms = room;
}

void Hotel::newEmployee(Employee employee)
{
    employees.append(employee);
}

void Hotel::firingEmployee(Employee employee)
{/*
    QList<Employee>::iterator iter = employees.begin();
    while(iter != employees.end()){
        if((*iter).getEmployeeNo() == employee.getEmployeeNo())
            employees.erase(iter);
        iter++;
    }
*/
}

void  Hotel::newService(Service service)
{
    services.append(service);
}

void  Hotel::deleteService(Service service)
{
    QList<Service>::iterator iter = services.begin();
    while(iter != services.end()){
        if((*iter).getType() == service.getType())
            services.erase(iter);
        iter++;
    }
}
