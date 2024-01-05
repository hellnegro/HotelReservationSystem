/**
 * @class MainWindow
 * @brief The main entry point for the hotel management system application.
 *
 * The ApplicationMain class initializes the QApplication instance, creates the main login
 * page, and starts the application loop. It serves as the starting point for the execution
 * of the hotel management system.
 *
 * @note This class sets up and launches the main user interface of the application.
 */


#include "loginpage.h"
#include <QApplication>
#include <QList>

/**
 * @brief The main function for the hotel management system application.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return The exit code of the application.
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    MainWindow w;    
    w.show();
    return a.exec();
}

