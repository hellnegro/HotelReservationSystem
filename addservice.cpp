/**
 * @class AddService
 * @brief Manages the addition of services in the hotel management system.
 *
 * The AddService class provides a user interface for adding services to specific rooms.
 * It allows users to select a room and choose from a predefined list of services.
 *
 * @note This class is part of the hotel management system, contributing to the service management functionality.
 */

#include "addservice.h"
#include "ui_addservice.h"


/**
 * @brief Constructs an AddService object.
 * @param parent The parent widget.
 */

AddService::AddService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddService)
{
    ui->setupUi(this);
    this->setFixedSize(550,250);
    const QList<QString> rooms = {"101","102","103","104","105","106","201","202","203","301","302"};
    ui->comboBox_Room->addItems(rooms);
    const QList<QString> service = {"BREAKFAST IN THE ROOM","WAKE UP","DINNER"};
    ui->comboBox_Service->addItems(service);
}
/**
 * @brief Destructor for the AddService class.
 */
AddService::~AddService()
{
    delete ui;
}

/**
 * @brief Slot function for the Cancel button click event.
 * @details Hides the current dialog.
 */
void AddService::on_pushButton_Cancel_clicked()
{
    this->hide();
}

