#include "booktheroom.h"
#include "ui_booktheroom.h"
#include "hotel.h"
#include <QMessageBox>

BookTheRoom::BookTheRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTheRoom)
{
    ui->setupUi(this);
    this->setFixedSize(550,300);
    readData();
}

void BookTheRoom:: readData()
{
    qDebug()<<"BookTheRoom:readData";
    std::vector<int> rooms = Hotel::getInstance()->getRoomList("y");
    std::vector<QString> customers = Hotel::getInstance()->getCustomerList("n");

    this->ui->comboBox_Room->clear();
    this->ui->comboBox_customer->clear();

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->comboBox_Room->addItem(QString::number(*it));
    }

    for(std::vector<QString>::iterator it = customers.begin(); it!=customers.end(); it++ )
    {
        this->ui->comboBox_customer->addItem(*it);
    }
}

void BookTheRoom::on_pushButton_Cancel_clicked()
{
    this->hide();
}


void BookTheRoom::on_pushButton_CheckIn_clicked()
{
    //call hotel's book room
    int  roomNo = ui->comboBox_Room->currentText().toInt();
    QString customer = ui->comboBox_customer->currentText();
    Hotel::getInstance()->bookRoom(roomNo,customer);
}

BookTheRoom::~BookTheRoom()
{
    delete ui;
}
