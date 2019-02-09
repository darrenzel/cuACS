#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QMainWindow>

namespace Ui {
class staffwindow;
}

class staffwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit staffwindow(QWidget *parent = 0);
    ~staffwindow();

private:
    Ui::staffwindow *ui;
};

#endif // STAFFWINDOW_H
