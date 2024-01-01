#include "availability.h"
#include "ui_availability.h"
#include "hotel.h"

Availability::Availability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availability)
{
    ui->setupUi(this);
    this->setFixedSize(600,350);
}

void Availability::readData()
{
    qDebug()<<"in readData()";

    std::vector<int>rooms = Hotel::getInstance()->getRoomList("y");

    std::vector<int>temprooms =  {101, 102, 103, 104, 105, 106, 201, 202, 203, 301, 302};

    //set default color to all
    for(std::vector<int>::iterator it = temprooms.begin(); it!=temprooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString labelName = "label_" + QString::number(*it);
        QLabel *ptr = this->findChild<QLabel*>(labelName);
        ptr->setStyleSheet("QLabel { background-color: red; }");
    }

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString labelName = "label_" + QString::number(*it);
        QLabel *ptr = this->findChild<QLabel*>(labelName);
        ptr->setStyleSheet("QLabel { background-color: green; }");
    }
}

Availability::~Availability()
{
    delete ui;
}
