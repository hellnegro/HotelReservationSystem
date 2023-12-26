#include "availability.h"
#include "ui_availability.h"

Availability::Availability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availability)
{
    ui->setupUi(this);
    this->setFixedSize(600,350);
}

Availability::~Availability()
{
    delete ui;
}
