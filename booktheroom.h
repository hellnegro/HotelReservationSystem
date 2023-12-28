#ifndef BOOKTHEROOM_H
#define BOOKTHEROOM_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class BookTheRoom;
}

class BookTheRoom : public QDialog
{
    Q_OBJECT

public:
    explicit BookTheRoom(QWidget *parent = nullptr);
    ~BookTheRoom();

private slots:
    void on_pushButton_Cancel_clicked();

private:
    Ui::BookTheRoom *ui;
};

#endif // BOOKTHEROOM_H
