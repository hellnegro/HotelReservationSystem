#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setFixedSize(380,380);
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/female.png"),"FEMALE");
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/male.png"),"MALE");
    ui->comboBox_status->addItem(QIcon(":/resource/icon/customer.png"),"CUSTOMER");
    ui->comboBox_status->addItem(QIcon(":/resource/icon/employee.png"),"EMPLOYEE");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_Cancel_clicked()
{
    this->hide();    
}

