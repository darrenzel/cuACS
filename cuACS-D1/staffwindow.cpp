#include "staffwindow.h"
#include "ui_staffwindow.h"

staffwindow::staffwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffwindow)
{
    ui->setupUi(this);
}

staffwindow::~staffwindow()
{
    delete ui;
}
