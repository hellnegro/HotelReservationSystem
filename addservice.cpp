#include "addservice.h"
#include "ui_addservice.h"

AddService::AddService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddService)
{
    ui->setupUi(this);
    this->setFixedSize(550,250);
    const QList<QString> rooms = {"101","102","103","104","105","106","201","202","203","301","302"};
    ui->comboBox_Room->addItems(rooms);
    const QList<QString> service = {"BREAKFAST IN THE ROOM","WAKE UP","DINNER"};
    ui->comboBox_Service->addItems(service);
}

AddService::~AddService()
{
    delete ui;
}

void AddService::on_pushButton_Cancel_clicked()
{
    this->hide();
}

