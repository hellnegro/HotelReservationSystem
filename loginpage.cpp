/**
 * @class LoginPage
 * @brief Implementation of the LoginPage class methods.
 *
 * The LoginPage class provides a simple interface for user authentication.
 * It includes a username and password input field, along with an icon for visual
 * representation. Upon successful login, it opens the main home page of the system.
 *
 * @note This class is responsible for handling user login interactions.
 */



#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include <QPixmap>


/**
 * @brief Constructor for the LoginPage class.
 * @param parent The parent widget -default is nullptr-
 */

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

/**
 * @brief Destructor for the LoginPage class.
 */

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief Slot function for the login button click event.
 * @details Checks the entered username and password, and opens the home page on success.
 * Otherwise, displays a warning message.
 */

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

