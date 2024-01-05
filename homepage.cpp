/**
 * @class HomePage
 * @brief Serves as the main hub for the hotel management system.
 *
 * The HomePage class provides a central interface for accessing various functionalities
 * such as client registration, room booking, check-out, availability check, transactions,
 * and service addition. The class includes methods to handle button clicks for each
 * functionality, creating and displaying corresponding dialogs.
 *
 * The UI is designed with fixed size and an embedded image, enhancing the visual experience.
 * Each button click triggers the creation of a new dialog instance and its display to the user.
 *
 * @note This class serves as the central point for user interactions within the hotel application.
 */


#include "homepage.h"
#include "ui_homepage.h"


/**
 * @brief Constructor for the HomePage class.
 * @param parent The parent widget (default is nullptr).
 */

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

/**
 * @brief Destructor for the HomePage class.
 */

HomePage::~HomePage()
{
    delete ui;
    delete registeration;
    delete paymentpage;
    delete available;
    delete booking;
}

/**
 * @brief Slot function for the "Register Client" button click event.
 * @details Creates and displays the Registration dialog.
 */

void HomePage::on_pushButton_RegisterClient_clicked()
{
    registeration = new Registration(this);
    registeration->show();
}

/**
 * @brief Slot function for the "Check Out" button click event.
 * @details Creates and displays the PaymentPage dialog with pre-loaded data.
 */

void HomePage::on_pushButton_CheckOut_clicked()
{
    paymentpage = new PaymentPage(this);
    paymentpage->readData();
    paymentpage->show();
}

/**
 * @brief Slot function for the "Check Availability" button click event.
 * @details Creates and displays the Availability dialog with updated data.
 */

void HomePage::on_pushButton_clicked()
{
    available = new Availability(this);
    available->readData();
    available->show();
}

/**
 * @brief Slot function for the "Book Room" button click event.
 * @details Creates and displays the BookTheRoom dialog with updated data.
 */


void HomePage::on_pushButton_BookRoom_clicked()
{
    booking = new BookTheRoom(this);
    booking->readData();
    booking->show();
}

/**
 * @brief Slot function for the "View Transactions" button click event.
 * @details Creates and displays the Transactions dialog with updated data.
 */

void HomePage::on_pushButton_transactions_clicked()
{
    transactions = new Transactions(this);
    transactions->readData();
    transactions->show();
}

/**
 * @brief Slot function for the "Add Service" button click event.
 * @details Creates and displays the AddService dialog.
 */

void HomePage::on_pushButton_addService_clicked()
{
    addservice = new AddService(this);
    addservice->show();
}

