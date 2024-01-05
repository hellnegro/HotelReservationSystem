/**
 * @class Registration
 * @brief Manages the registration process for adding new customers or employees.
 *
 * The Registration class provides an interface for users to register as customers or employees.
 * Users can input their personal information, and based on the selected status, the system
 * registers them as customers or employees.
 *
 * @note This class oversees the registration procedures in the hotel management system.
 */


#include "registration.h"
#include "ui_registration.h"
#include "Customer.h"
#include "employee.h"

/**
 * @brief Constructor for the Registration class.
 * @param parent The parent widget (default is nullptr).
 */

Registration::Registration(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setFixedSize(380,380);
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/male.png"),"MALE");
    ui->comboBox_gender->addItem(QIcon(":/resource/icon/female.png"),"FEMALE");    
    ui->comboBox_status->addItem(QIcon(":/resource/icon/customer.png"),"CUSTOMER");
    ui->comboBox_status->addItem(QIcon(":/resource/icon/employee.png"),"EMPLOYEE");
}

/**
 * @brief Destructor for the Registration class.
 */

Registration::~Registration()
{
    delete ui;
}


/**
 * @brief Slot function for the cancel button click event.
 * @details Closes the registration page dialog without performing any actions.
 */

void Registration::on_pushButton_Cancel_clicked()
{
    this->hide();    
}


/**
 * @brief Slot function for the status combo box index change event.
 * @details Shows or hides relevant input fields based on the selected status (customer or employee).
 * If employee is selected, position-related fields are displayed; otherwise, phone and email fields are shown.
 */

void Registration::on_comboBox_status_currentIndexChanged(int index)
{
    if(index == 1)
    {
        ui->label_phone->hide();
        ui->label_email->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_email->hide();
        ui->label_position->show();
        ui->lineEdit_position->show();
    }else{
        ui->label_phone->show();
        ui->label_email->show();
        ui->lineEdit_phone->show();
        ui->lineEdit_email->show();
        ui->label_position->hide();
        ui->lineEdit_position->hide();
    }
}

/**
 * @brief Slot function for the submit button click event.
 * @details Processes the registration based on the selected status. Registers customers or employees
 * in the hotel management system and hides the registration page upon successful registration.
 */

void Registration::on_pushButton_Submit_clicked()
{
    if(ui->comboBox_status->currentIndex()==0)
    {
        QString firstName = ui->lineEdit_name->text();
        QString lastName = ui->lineEdit_surname->text();
        short age = ui->lineEdit_age->text().toShort();
        QString gender = ui->comboBox_gender->currentText();
        QString phoneNumber = ui->lineEdit_phone->text();
        QString email = ui->lineEdit_email->text();

        Customer customer = Customer(firstName,lastName,age,gender,phoneNumber,email);
        int customerNo = Hotel::getInstance()->registerCustomer(customer);
        customer.setCustomerNo(customerNo);
        this->hide();
    }else{
        QString firstName = ui->lineEdit_name->text();
        QString lastName = ui->lineEdit_surname->text();
        short age = ui->lineEdit_age->text().toShort();
        QString gender = ui->comboBox_gender->currentText();
        QString position = ui->lineEdit_position->text();

        Employee employee = Employee(firstName,lastName,age,gender,position);
        int employeeNo = Hotel::getInstance()->registerEmployee(employee);
        employee.setEmployeeNo(employeeNo);
        this->hide();
    }
}

