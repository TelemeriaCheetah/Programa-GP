#include "backlog.h"
#include "ui_backlog.h"

extern QString estilo_normal;
extern Dados_jogador pz;

Backlog::Backlog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Backlog)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet(estilo_normal);
}

Backlog::~Backlog()
{
    delete ui;
}

void Backlog::on_btn_atualiza_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM "+pz.getPokerTable()+"_sprint ");
    query.exec();

    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery(query);
    ui->tableView->setModel(modal);
}

void Backlog::on_tableView_doubleClicked(const QModelIndex &index)
{

}

void Backlog::on_btn_planejar_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        //qDebug() << index.row();
         qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString();
    }

}
