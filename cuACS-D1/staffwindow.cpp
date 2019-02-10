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
    QString name, color,age,id;

    name = ui->lineEdit_name->text();
    color=ui->lineEdit_color->text();
    age=ui->lineEdit_age->text();
    id=ui->lineEdit_id->text();
    MainWindow mw;
    if(!mw.conopen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    query.exec("insert into pet values('"+name+"','"+age+"','"+color+"','"+id+"');");
    mw.conclose();
    displaypet();
}
