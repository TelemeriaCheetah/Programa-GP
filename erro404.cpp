#include "erro404.h"
#include "ui_erro404.h"

erro404::erro404(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::erro404)
{
    ui->setupUi(this);
}

erro404::~erro404()
{
    delete ui;
}
