#include "registration.h"
#include "ui_registration.h"
#include "Customer.h"
#include "employee.h"

Registration::Registration(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setFixedSize(380,380);
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/male.png"),"MALE");
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/female.png"),"FEMALE");    
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


void Registration::on_comboBox_status_currentIndexChanged(int index)
{
    if(index == 1)
    {
        ui->label_phone->hide();
        ui->label_email->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_email->hide();
        ui->label_position->show();
        ui->lineEdit_position->show();
    }else{
        ui->label_phone->show();
        ui->label_email->show();
        ui->lineEdit_phone->show();
        ui->lineEdit_email->show();
        ui->label_position->hide();
        ui->lineEdit_position->hide();
    }
}


void Registration::on_pushButton_Submit_clicked()
{
    if(ui->comboBox_status->currentIndex()==0)
    {
        QString firstName = ui->lineEdit_name->text();
        QString lastName = ui->lineEdit_surname->text();
        short age = ui->lineEdit_age->text().toShort();
        QString gender = ui->comboBox_gender->currentText();
        QString phoneNumber = ui->lineEdit_phone->text();
        QString email = ui->lineEdit_email->text();

        Customer customer = Customer(firstName,lastName,age,gender,phoneNumber,email);
        Hotel::getInstance()->registerCustomer(customer);
        this->hide();
    }else{
        QString firstName = ui->lineEdit_name->text();
        QString lastName = ui->lineEdit_surname->text();
        short age = ui->lineEdit_age->text().toShort();
        QString gender = ui->comboBox_gender->currentText();
        QString position = ui->lineEdit_position->text();

        Employee employee = Employee(firstName,lastName,age,gender,position);
        Hotel::getInstance()->registerEmployee(employee);
        this->hide();
    }
}

