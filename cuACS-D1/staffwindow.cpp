#include "staffwindow.h"
#include "ui_staffwindow.h"

staffwindow::staffwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffwindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("/home/student/Desktop/cuACS/data/database.db");


  QSqlQueryModel* modal = new QSqlQueryModel();
  QSqlQuery query;

  query.exec("select * from pet");
  modal->setQuery(query);
  ui->tableView->setModel(modal);
}

staffwindow::~staffwindow()
{
    delete ui;
}

void staffwindow::on_pushButton_clicked()
{
    QString name, color,age,id;

    name = ui->lineEdit_name->text();
    color=ui->lineEdit_color->text();
    age=ui->lineEdit_age->text();
    id=ui->lineEdit_id->text();

    if(!db.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    query.exec("insert into pet values('"+name+"','"+age+"','"+color+"','"+id+"');");
}
