#include "loginpage.h"
#include "hotel.h"
#include "system.h"
#include "service.h"
#include "Room.h"
#include <QApplication>
#include <QList>

int main(int argc, char *argv[])
{
    System system = System();
    QList<Room> rooms = {{"101","SINGLE",750.00},
                    {"102","SINGLE",750.00},
                    {"103","SINGLE",750.00},
                    {"104","SINGLE",750.00},
                    {"105","SINGLE",750.00},
                    {"106","SINGLE",750.00},
                    {"201","DOUBLE",1350.00},
                    {"202","DOUBLE",1350.00},
                    {"203","DOUBLE",1350.00},
                    {"301","SUIT",1750},
                    {"301","SUIT",1750}};
    QList<Service> services = {{1,"BREAKFAST IN THE ROOM",450.00},
                        {1,"WAKE UP",175.00},
                        {1,"DINNER",650.00}};

    Hotel::getInstance()->setServices(services);
    Hotel::getInstance()->setRooms(rooms);
    QApplication a(argc, argv);    
    MainWindow w;    
    w.show();
    return a.exec();
}

