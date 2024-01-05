/**
 * @class Availability
 * @brief Implementation of the Availability class methods.
 *
 * The Availability class represents a dialog in the hotel management system
 * for displaying the availability status of rooms. It is responsible for
 * updating the user interface based on the current room availability information
 * obtained from the Hotel class.
 *
 * The class includes a constructor for initializing the dialog and setting its size.
 * The readData method retrieves room availability information from the Hotel class,
 * then adjusts the color of corresponding labels in the UI to indicate availability.
 * The destructor ensures proper cleanup of UI resources.
 */


#include "availability.h"
#include "ui_availability.h"
#include "hotel.h"
/**
 * @brief Constructor for the Availability class.
 * @param parent The parent widget (default is nullptr).
 */
Availability::Availability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availability)
{
    ui->setupUi(this);
    this->setFixedSize(600,350);
}

/**
 * @brief Reads data and updates the availability status of rooms.
 * @details Uses the Hotel class to retrieve room availability information,
 *          then adjusts the color of corresponding labels in the UI.
 */

void Availability::readData()
{
    qDebug()<<"in readData()";

    std::vector<int>rooms = Hotel::getInstance()->getRoomList("y");

    std::vector<int>temprooms =  {101, 102, 103, 104, 105, 106, 201, 202, 203, 301, 302};

    //set default color to all
    for(std::vector<int>::iterator it = temprooms.begin(); it!=temprooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString labelName = "label_" + QString::number(*it);
        QLabel *ptr = this->findChild<QLabel*>(labelName);
        ptr->setStyleSheet("QLabel { background-color: rgb(255, 0, 0); }");
    }

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        //Put logic to change color of Labels
        QString labelName = "label_" + QString::number(*it);
        QLabel *ptr = this->findChild<QLabel*>(labelName);
        ptr->setStyleSheet("QLabel { background-color: rgb(0, 255, 0); }");
    }
}

/**
 * @brief Destructor for the Availability class.
 */

Availability::~Availability()
{

    delete ui;

}
