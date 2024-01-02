#include "booktheroom.h"
#include "ui_booktheroom.h"
#include "hotel.h"

BookTheRoom::BookTheRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTheRoom)
{
    ui->setupUi(this);
    this->setFixedSize(550,300);
}

int BookTheRoom::getRoomNo()
{
    return roomNo;
}

void BookTheRoom::setRoomNo(int no)
{
    roomNo = no;
}

int BookTheRoom::getCustomerNo()
{
    return customerNo;
}

void BookTheRoom::setCustomerNo(int no)
{
    customerNo = no;
}

void BookTheRoom:: readData()
{
    qDebug()<<"BookTheRoom:readData";
    std::vector<int> rooms = Hotel::getInstance()->getRoomList("y");
    std::vector<std::vector<QString>> customers = Hotel::getInstance()->getCustomerList("n");

    this->ui->comboBox_Room->clear();
    this->ui->comboBox_customer->clear();

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->comboBox_Room->addItem(QString::number(*it));
    }

    for(unsigned long long i=0; i < customers.size(); i++ )
    {
        std::string seperator = ") ";
        std::string tab = "\t";
        QString fullName = customers[i][0].append(seperator).append(customers[i][1]).append(tab).append(customers[i][2].toStdString());
        this->ui->comboBox_customer->addItem(fullName);

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
    setRoomNo(roomNo);
    QString customer = ui->comboBox_customer->currentText();
    setCustomerNo(customer.split(")")[0].toInt());
    Hotel::getInstance()->bookRoom(roomNo,getCustomerNo());
    this->hide();
}

BookTheRoom::~BookTheRoom()
{
    delete ui;
}
