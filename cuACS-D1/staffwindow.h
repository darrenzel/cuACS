#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include "mainwindow.h"
namespace Ui {
class staffwindow;
}

class staffwindow : public QDialog
{
    Q_OBJECT

public:
    explicit staffwindow(QWidget *parent = 0);
    ~staffwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::staffwindow *ui;
    QSqlDatabase db;
    void displaypet();

};

#endif // STAFFWINDOW_H
