/*
Author: Shuaijie Xu
Student ID: 251187747
Date: 2021-09-31
Description: MainWindow class contains all the member and functions that are going to use
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QTextEdit>

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
  void handleExecuteButton();
  void itemDoubleClick(QListWidgetItem*);
private:
  QLabel *label;
  QPushButton *executeButton;
  QLineEdit *userinputLineEdit;
  QLabel *outputLabel;
  QTextEdit *displayOutputTextedit;
  QLabel *exitStatusLabel;
  QLabel *exitStatusValueLabel;
  QLabel *separateLineLabel;
  QLabel *historyLabel;
  QListWidget *displayHistoryList;
  QVector<QString> outputHistory;
  QString userInput;
  QString result;
  QString exitStatus;
};
#endif // MAINWINDOW_H

