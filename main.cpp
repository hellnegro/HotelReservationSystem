#include "loginpage.h"
//#include "room.h"


#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    Room rooms[] = {{"101","SINGLE",150},
                    {"102","SINGLE",150},
                    {"103","SINGLE",150},
                    {"104","SINGLE",150},
                    {"105","SINGLE",150},
                    {"106","SINGLE",150},
                    {"201","DOUBLE",250},
                    {"202","DOUBLE",250},
                    {"203","DOUBLE",250},
                    {"301","SUIT",450},
                    {"301","SUIT",450}};

    for(Room r:rooms){
        qDebug() << r.getInfo();
    }
*/
    MainWindow w;
    w.show();
    return a.exec();
}
