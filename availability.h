#ifndef AVAILABILITY_H
#define AVAILABILITY_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class Availability;
}

class Availability : public QDialog
{
    Q_OBJECT

public:
    explicit Availability(QWidget *parent = nullptr);
    ~Availability();
    void readData();

private:
    Ui::Availability *ui;
};

#endif // AVAILABILITY_H
