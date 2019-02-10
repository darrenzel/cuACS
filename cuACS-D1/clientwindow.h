#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();

private:
    Ui::clientwindow *ui;
    void displaypet();
    QSqlDatabase db;


};

#endif // CLIENTWINDOW_H
