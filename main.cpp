/*
Author: Shuaijie Xu
Student ID: 251187747
Date: 2021-09-31
Description: 
-main function to create and show a window
*/
#include "mainwindow.h"
#include "command.h"
#include <QApplication>
 
int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    mainWindow.setGeometry(0,0,350,450);
    return app.exec();
}
