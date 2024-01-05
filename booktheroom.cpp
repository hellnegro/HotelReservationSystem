/**
 * @class BookTheRoom
 * @brief Represents a dialog for booking hotel rooms.
 *
 * The BookTheRoom class provides a dialog window allowing users to book hotel rooms.
 * It includes methods for reading data, handling user actions such as canceling the booking
 * or checking in, and interacting with the Hotel class to update room booking status.
 * Users can select a room and a customer from the available lists and perform booking actions.
 *
 * The class maintains information about the selected room number and customer number.
 * The readData method populates the UI components with the current list of available rooms
 * and customers from the Hotel class. The CheckIn button triggers the booking process by
 * calling the bookRoom method of the Hotel class.
 *
 * @note This class is a component of the hotel management system, providing functionality
 * for booking rooms and managing customer information.
 */





#include "booktheroom.h"
#include "ui_booktheroom.h"
#include "hotel.h"


BookTheRoom::BookTheRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTheRoom)
{
    ui->setupUi(this);
    this->setFixedSize(550,300);
}



/**
 * @brief Gets the currently selected room number.
 * @return The selected room number.
 */


int BookTheRoom::getRoomNo()
{
    return roomNo;
}


/**
 * @brief Sets the room number to be booked.
 * @param no The room number to be set.
 */


void BookTheRoom::setRoomNo(int no)
{
    roomNo = no;
}

/**
 * @brief Gets the customer number for the booking.
 * @return The selected customer number.
 */



int BookTheRoom::getCustomerNo()
{
    return customerNo;
}


/**
 * @brief Sets the customer number for the booking.
 * @param no The customer number to be set.
 */



void BookTheRoom::setCustomerNo(int no)
{
    customerNo = no;
}


/**
 * @brief Reads and updates data for room and customer lists from the Hotel class.
 */


void BookTheRoom:: readData()
{
    qDebug()<<"BookTheRoom:readData";
    std::vector<int> rooms = Hotel::getInstance()->getRoomList("y");
    std::vector<std::vector<QString>> customers = Hotel::getInstance()->getCustomerList("n");

    this->ui->comboBox_Room->clear();
    this->ui->comboBox_customer->clear();

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->comboBox_Room->addItem(QString::number(*it));
    }

    for(unsigned long long i=0; i < customers.size(); i++ )
    {
        std::string seperator = ") ";
        std::string tab = "\t";
        QString fullName = customers[i][0].append(seperator).append(customers[i][1]).append(tab).append(customers[i][2].toStdString());
        this->ui->comboBox_customer->addItem(fullName);

    }
}


/**
 * @brief Slot function for the Cancel button click event.
 * @details Hides the current dialog.
 */


void BookTheRoom::on_pushButton_Cancel_clicked()
{
    this->hide();
}


/**
 * @brief Slot function for the Check In button click event.
 * @details Initiates the booking process by calling the bookRoom method of the Hotel class.
 * The selected room number and customer number are retrieved from the UI components.
 */


void BookTheRoom::on_pushButton_CheckIn_clicked()
{
    //call hotel's book room
    int  roomNo = ui->comboBox_Room->currentText().toInt();
    setRoomNo(roomNo);
    QString customer = ui->comboBox_customer->currentText();
    setCustomerNo(customer.split(")")[0].toInt());
    Hotel::getInstance()->bookRoom(roomNo,getCustomerNo());
    this->hide();
}


/**
 * @brief Destructor for the BookTheRoom class.
 */

BookTheRoom::~BookTheRoom()
{
    delete ui;
}
