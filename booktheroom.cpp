#include "booktheroom.h"
#include "ui_booktheroom.h"

BookTheRoom::BookTheRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTheRoom)
{
    ui->setupUi(this);
    this->setFixedSize(550,300);
    const QList<QString> rooms = {"101","102","103","104","105","106","201","202","203","301","302"};
    ui->comboBox_Room->addItems(rooms);
}

BookTheRoom::~BookTheRoom()
{
    delete ui;
}

void BookTheRoom::on_pushButton_Cancel_clicked()
{
    this->hide();
}

