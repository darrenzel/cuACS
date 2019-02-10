#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/Desktop/cuACS/data/database.db");

    if(!db.open()){
        ui->label->setText("failed to open the database");
    }else{
        ui->label->setText("connected to database");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clientlogin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(!db.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from client where username='"+username+"' and password='"+password+"'")){
        int count=0;
        while(query.next()){
            count++;
        }
        if(count==1){
             QMessageBox::information(this,"Login","Welcome to client page");
             //this->hide();
             //staffwindow staff;

             //staff.show();
        }else if(count<1){
            QMessageBox::warning(this,"Login","username or password is incorrect");
        }else{
            QMessageBox::warning(this,"Login","login failed");

        }
    }
}

void MainWindow::on_pushButton_stafflogin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(!db.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from staff where username='"+username+"' and password='"+password+"'")){
        int count=0;
        while(query.next()){
            count++;
        }
        if(count==1){
             QMessageBox::information(this,"Login","Welcome to staff page");
             this->hide();
             staffwindow staff;
             staff.setModal(true);
             staff.exec();
        }else if(count<1){
            QMessageBox::warning(this,"Login","username or password is incorrect");
        }else{
            QMessageBox::warning(this,"Login","login failed");

        }
    }
}
