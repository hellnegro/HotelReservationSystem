#include "transactions.h"
#include "ui_transactions.h"
#include "hotel.h"

Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);
    this->setFixedSize(565,530);
}

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


Transactions::~Transactions()
{
    delete ui;
}
