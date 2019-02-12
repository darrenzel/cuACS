#include "staffwindow.h"
#include "ui_staffwindow.h"

staffwindow::staffwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffwindow)
{
    ui->setupUi(this);
    displaypet();
}

staffwindow::~staffwindow()
{
    delete ui;
}
void staffwindow::displaypet(){
    MainWindow mw;
    if(!mw.conopen()){
        qDebug()<<("failed to open the database");
    }else{
       qDebug()<<("connected to database");
    }

  QSqlQueryModel* modal = new QSqlQueryModel();
  QSqlQuery* qry = new QSqlQuery(db);

  qry->prepare("select * from pet");
  qry->exec();
  modal->setQuery(*qry);
  ui->tableView->setModel(modal);
  mw.conclose();
}
void staffwindow::on_pushButton_clicked()
{
    QString name, color,age,id, sex, size, breed;

    name = ui->lineEdit_name->text();
    color=ui->lineEdit_color->text();
    age=ui->lineEdit_age->text();
    id=ui->lineEdit_id->text();
    breed = ui->lineEdit_breed->text();
    sex=ui->lineEdit_sex->text();
    size=ui->lineEdit_size->text();
    MainWindow mw;
    if(!mw.conopen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    query.exec("insert into pet values('"+id+"','"+name+"','"+breed+"','"+age+"','"+color+"','"+size+"','"+sex+"');");
    mw.conclose();
    ui->lineEdit_name->clear();
    ui->lineEdit_color->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_id->clear();
    ui->lineEdit_breed->clear();
    ui->lineEdit_sex->clear();
    ui->lineEdit_size->clear();
    displaypet();
}
