#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setFixedSize(840,480);

    //Path to image file
    QPixmap roomImg(":/resource/image/room.png");
    ui->label_Image->setPixmap(roomImg);
    ui->label_Image->setScaledContents(true);
}

HomePage::~HomePage()
{
    delete ui;
    delete registeration;
    delete paymentpage;
    delete available;
    delete booking;
}

void HomePage::on_pushButton_RegisterClient_clicked()
{
    registeration = new Registration(this);
    registeration->show();
}

void HomePage::on_pushButton_CheckOut_clicked()
{
    paymentpage = new PaymentPage(this);
    paymentpage->show();
}


void HomePage::on_pushButton_clicked()
{
    available = new Availability(this);
    available->show();
}


void HomePage::on_pushButton_BookRoom_clicked()
{
    booking = new BookTheRoom(this);
    booking->show();
}


void HomePage::on_pushButton_transactions_clicked()
{
    transactions = new Transactions(this);
    transactions->show();
}


void HomePage::on_pushButton_addService_clicked()
{
    addservice = new AddService(this);
    addservice->show();
}

