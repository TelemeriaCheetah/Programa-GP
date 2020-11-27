#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class loginForm;
}

class loginForm : public QDialog
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();

private slots:
    void on_btn_login_clicked();

private:
    Ui::loginForm *ui;
    MainWindow *mainWindow;
};

#endif // LOGINFORM_H
