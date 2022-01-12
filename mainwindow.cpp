/*
Author: Shuaijie Xu
Student ID: 251187747
Date: 2021-09-31
Description: MainWindow() initialize all memebers of class
when button is clicked and then released, the handlExecuteButton gets called
when user double clicked an item in the HistoryListField, the itemDoubleClick function gets call
*/
#include "mainwindow.h"
#include <iostream>
#include "command.h"
#include <vector>

/*
function name: MainWindow
description: a constructor to initialize all the memebers of MainWindow class
it also create all the layout that are required in the GUI
parameter descriptions: receive parent
*/
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
  userInput = QString();
  result = QString();
  exitStatus = QString();

  label = new QLabel("Command:",this);
  label->setGeometry(QRect(QPoint(20,20),QSize(100,25)));

  userinputLineEdit = new QLineEdit("",this);
  userinputLineEdit->setGeometry(QRect(QPoint(100,20),QSize(100,25)));
  connect(userinputLineEdit, &QLineEdit::returnPressed, this, &MainWindow::handleExecuteButton);//connect userinputLineEdit to handleExecuteButton by signal returnPressed since if user press "Enter", it same as press the ExecuteButton

  executeButton = new QPushButton("Execute", this);
  executeButton->setGeometry(QRect(QPoint(220, 20), QSize(100, 25)));
  connect(executeButton, &QPushButton::released, this, &MainWindow::handleExecuteButton);//connect executeButton to handleExecuteButton by signal released

  outputLabel = new QLabel("Output:",this);
  outputLabel->setGeometry(QRect(QPoint(20,45),QSize(100,25)));

  displayOutputTextedit = new QTextEdit("",this);
  displayOutputTextedit->setGeometry(QRect(QPoint(20,70),QSize(310,150)));
  displayOutputTextedit->setReadOnly(true);//set it display area to read only

  exitStatusLabel = new QLabel("Exit status:",this);
  exitStatusLabel->setGeometry(QRect(QPoint(20,220),QSize(70,25)));

  exitStatusValueLabel = new QLabel("",this);
  exitStatusValueLabel->setGeometry(QRect(QPoint(95,220),QSize(11,25)));

  separateLineLabel = new QLabel("--------------------------------------------------------------------------------------",this);
  separateLineLabel->setGeometry(QRect(QPoint(20,240),QSize(310,10)));

  historyLabel = new QLabel("History:",this);
  historyLabel->setGeometry(QRect(QPoint(20,250),QSize(100,25)));

  displayHistoryList = new QListWidget(this);
  displayHistoryList->setGeometry(QRect(QPoint(20,275),QSize(310,150)));
  connect(displayHistoryList,&QListWidget::itemDoubleClicked, this, &MainWindow::itemDoubleClick);//connect displayHistoryList to itemDoubleClick by signal itemDoubleClicked

}
/*
function name: hadleExecuteButton
description: when user click the button and released, this function get call
and then it will get userinput first and start to execute user input, after that it set the display area to show the result of user input
store the output in a vector
*/
void MainWindow::handleExecuteButton()
{
  userInput = userinputLineEdit->text();//get userinput
  Command command(userInput.toStdString());//change QString to String
  command.execute();
  result = QString::fromStdString(command.get_result());//change String to QString
  displayOutputTextedit->setText(result);

  exitStatus = QString::number(command.get_return_code());
  exitStatusValueLabel->setText(exitStatus);//set exitStatus

  QListWidgetItem *newItem = new QListWidgetItem;
  QString newItemText = QString::number(displayHistoryList->count()+1) + "." + userInput + "(" + exitStatus + ")";//change number to QString
  newItem->setText(newItemText);
  displayHistoryList->insertItem(displayHistoryList->count(),newItem);//set display history area

  outputHistory.push_back(result);//store command result into vector
  
}

/*
function name: itemDoubleClick
description: it get the row number of selected item, search in the vector and display in the history area
parameter description: it receive an item in the list that are double click by user
*/
void MainWindow::itemDoubleClick(QListWidgetItem* item)
{ 
  int row = displayHistoryList->row(item);//get the row number in the list so that we can find the postion in vector
  displayOutputTextedit->setText(outputHistory.at(row));
}




