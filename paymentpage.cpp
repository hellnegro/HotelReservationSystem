#include "paymentpage.h"
#include "ui_paymentpage.h"

PaymentPage::PaymentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentPage)
{
    ui->setupUi(this);
    const QList<QString> rooms = {"101","102","103","104","105","106","201","202","203","301","302"};
    ui->comboBox_RoomNo->addItems(rooms);
    const QList<QString> methods = {"CASH","CREDIT CARD","EFT","MOBILE PAYMENTS"};
    ui->comboBox_PaymentMethod->addItems(methods);
}

PaymentPage::~PaymentPage()
{
    delete ui;
}

void PaymentPage::on_pushButton_Cancel_clicked()
{
    this->hide();
}

