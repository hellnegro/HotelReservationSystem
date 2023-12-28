#ifndef PAYMENTPAGE_H
#define PAYMENTPAGE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class PaymentPage;
}

class PaymentPage : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentPage(QWidget *parent = nullptr);
    ~PaymentPage();

private slots:
    void on_pushButton_Cancel_clicked();

private:
    Ui::PaymentPage *ui;
};

#endif // PAYMENTPAGE_H
