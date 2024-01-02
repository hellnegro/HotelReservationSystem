#ifndef BOOKTHEROOM_H
#define BOOKTHEROOM_H

#include <QDialog>
#include <QDebug>
#include <vector>

namespace Ui {
class BookTheRoom;
}

class BookTheRoom : public QDialog
{
    Q_OBJECT

public:
    explicit BookTheRoom(QWidget *parent = nullptr);
    ~BookTheRoom();
    void readData();
    int getRoomNo();
    int getCustomerNo();
    void setRoomNo(int);
    void setCustomerNo(int);

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_CheckIn_clicked();

private:
    Ui::BookTheRoom *ui;
    int roomNo;
    int customerNo;
};

#endif // BOOKTHEROOM_H
