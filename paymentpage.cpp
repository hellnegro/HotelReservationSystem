/**
 * @class PaymentPage
 * @brief Represents the payment page for handling check-out transactions.
 *
 * The PaymentPage class provides an interface for processing check-out payments
 * for rooms. It displays a list of available rooms and payment methods. Upon successful
 * check-out, it triggers the check-out process in the hotel management system.
 *
 * @note This class is responsible for managing payment transactions during the check-out process.
 */


#include "paymentpage.h"
#include "ui_paymentpage.h"
#include <QMessageBox>
#include "hotel.h"

/**
 * @brief Constructor for the PaymentPage class.
 * @param parent The parent widget (default is nullptr).
 */

PaymentPage::PaymentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentPage)
{
    ui->setupUi(this);
    const QList<QString> methods = {"CASH","CREDIT CARD","EFT","MOBILE PAYMENTS"};
    ui->comboBox_PaymentMethod->addItems(methods);
}

/**
 * @brief Reads and displays the data required for the payment process.
 * @details Retrieves a list of rooms from the hotel management system and populates
 * the room number combo box. Enables the payment button if rooms are available for check-out.
 */

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

/**
 * @brief Destructor for the PaymentPage class.
 */

PaymentPage::~PaymentPage()
{
    delete ui;
}

/**
 * @brief Slot function for the cancel button click event.
 * @details Closes the payment page dialog without performing any actions.
 */

void PaymentPage::on_pushButton_Cancel_clicked()
{
    this->hide();
}

/**
 * @brief Slot function for the payment button click event.
 * @details Initiates the check-out process for the selected room by calling the hotel's check-out method.
 * Displays appropriate messages based on the check-out result.
 */

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

