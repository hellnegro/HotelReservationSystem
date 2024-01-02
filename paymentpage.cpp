#include "paymentpage.h"
#include "ui_paymentpage.h"
#include <QMessageBox>
#include "hotel.h"

PaymentPage::PaymentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentPage)
{
    ui->setupUi(this);
    const QList<QString> methods = {"CASH","CREDIT CARD","EFT","MOBILE PAYMENTS"};
    ui->comboBox_PaymentMethod->addItems(methods);
}

void PaymentPage::readData()
{
    std::vector<int>rooms = Hotel::getInstance()->getRoomList("n");
    this->ui->comboBox_RoomNo->clear();
    char flag = 0;
    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->comboBox_RoomNo->addItem(QString::number(*it));
        flag = 1;
    }

    if(flag==1) this->ui->pushButton_Payment->setEnabled(true);

}

PaymentPage::~PaymentPage()
{
    delete ui;
}

void PaymentPage::on_pushButton_Cancel_clicked()
{
    this->hide();
}

void PaymentPage::on_pushButton_Payment_clicked()
{
    //call hotels's checkout
    int  roomNo = ui->comboBox_RoomNo->currentText().toInt();

    if(roomNo < 1)
    {
        QMessageBox::information(
            this,
            tr("Warning!"),
            tr("No room to Check out") );
        return;
    }
    int ret = Hotel::getInstance()->checkOut(roomNo);

    this->hide();

    if(ret == 0)
    {
        QMessageBox::information(
            this,
            tr("Success!"),
            tr("Room has been Check-out! Say thank you to Customer") );
    }
}

