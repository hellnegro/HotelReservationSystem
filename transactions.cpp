#include "transactions.h"
#include "ui_transactions.h"
#include "hotel.h"

Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);
    this->setFixedSize(565,530);
    readData();
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
    query.prepare("select * from cppbuzz_transaction");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();


    while(query.next())
    {

        this->ui->listWidget->addItem(query.value(0).toString() +"************************"+ query.value(1).toString() +"****************"+ query.value(2).toString());
        qDebug() << query.value(0).toString() << " " << query.value(1).toString() << query.value(2).toString();
    }

    Database.close();
}


Transactions::~Transactions()
{
    delete ui;
}
