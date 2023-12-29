#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include <QDebug>

#include "registration.h"
#include "paymentpage.h"
#include "availability.h"
#include "booktheroom.h"
#include "transactions.h"
#include "addservice.h"

namespace Ui {
    class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_RegisterClient_clicked();

    void on_pushButton_CheckOut_clicked();

    void on_pushButton_clicked();

    void on_pushButton_BookRoom_clicked();

    void on_pushButton_transactions_clicked();

    void on_pushButton_addService_clicked();

private:
    Ui::HomePage *ui;
    Registration *registeration;
    PaymentPage *paymentpage;
    Availability *available;
    BookTheRoom *booking;
    Transactions *transactions;
    AddService *addservice;
};

#endif // HOMEPAGE_H
