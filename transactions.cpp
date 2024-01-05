/**
 * @class Transactions
 * @brief Manages and displays transaction information within the hotel management system.
 *
 * The Transactions class is responsible for retrieving and displaying transaction data
 * from the system's database. It provides functionality to read and present transaction details.
 *
 * @note This class is part of the hotel management system, contributing to the overall functionality
 * by handling transaction-related tasks.
 */


#include "transactions.h"
#include "ui_transactions.h"
#include "hotel.h"

/**
 * @brief Constructs a Transactions object.
 * @param parent The parent widget.
 */


Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);
    this->setFixedSize(565,530);
}

/**
 * @brief Reads transaction data from the system's database and populates the user interface.
 */

void Transactions:: readData()
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
    query.prepare("SELECT * FROM transaction");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();


    while(query.next())
    {
        QString room = query.value(0).toString();
        QString customerName = query.value(1).toString();
        QString customerSurname = query.value(2).toString();
        QString tab = " ";
        QString item = room.append(tab).append(customerName).append(tab).append(customerSurname);
        this->ui->listWidget->addItem(item);
        qDebug() << item;
    }

    Database.close();
}

/**
 * @brief Destroys the Transactions object.
 */

Transactions::~Transactions()
{
    delete ui;
}
