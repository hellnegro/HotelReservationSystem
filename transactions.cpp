#include "transactions.h"
#include "ui_transactions.h"

Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);
    this->setFixedSize(565,530);
}

Transactions::~Transactions()
{
    delete ui;
}
