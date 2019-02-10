#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include "staffwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase db;
    void conclose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool conopen(){
        db = QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName("/home/student/Desktop/cuACS/data/database.db");

      if(!db.open()){
         qDebug()<<("failed to open the database");
         return false;
      }else{
         qDebug()<<("connected to database");
         return true;
      }
    }
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clientlogin_clicked();

    void on_pushButton_stafflogin_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
