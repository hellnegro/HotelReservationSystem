#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,215);

    QPixmap iconImage(":/resource/icon/password.png");
    int w = ui->label_icon->width();
    int h = ui->label_icon->height();
    ui->label_icon->setPixmap(iconImage.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username == "test" && password == "123"){
        hide();
        homePage = new HomePage(this);
        homePage->show();
    } else {
        QMessageBox::warning(this,"Login","Username or password is not correct");
        ui->statusbar->showMessage("invalid value",5000);
    }
}

