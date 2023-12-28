#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QDebug>

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

private:
    Ui::Registration *ui;

};

#endif // REGISTRATION_H
