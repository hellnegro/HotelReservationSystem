#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "system.h"
#include "Customer.h"
#include "employee.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QDialog *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_Cancel_clicked();

    void on_comboBox_status_currentIndexChanged(int index);

    void on_pushButton_Submit_clicked();

private:
    Ui::Registration *ui;
    Customer *customer;
    Employee *employee;
};

#endif // REGISTRATION_H
