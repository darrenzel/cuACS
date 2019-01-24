#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clientlogin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "client" && password == "test"){
        QMessageBox::information(this,"Login","Welcome to client page");

    }
    else{
        QMessageBox::warning(this,"Login","username or password is incorrect");
    }
}

void MainWindow::on_pushButton_stafflogin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "staff" && password == "test"){
        QMessageBox::information(this,"Login","Welcome to staff page");

    }
    else{
        QMessageBox::warning(this,"Login","username or password is incorrect");
    }
}
