#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    displaypet();
}

clientwindow::~clientwindow()
{
    delete ui;
}
void clientwindow::displaypet(){
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
