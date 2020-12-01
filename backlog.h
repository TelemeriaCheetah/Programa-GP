#ifndef BACKLOG_H
#define BACKLOG_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtDebug>
#include "dados_jogador.h"

namespace Ui {
class Backlog;
}

class Backlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Backlog(QWidget *parent = nullptr);
    ~Backlog();

private slots:
    void on_btn_atualiza_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_btn_planejar_clicked();

private:
    Ui::Backlog *ui;
};

#endif // BACKLOG_H
