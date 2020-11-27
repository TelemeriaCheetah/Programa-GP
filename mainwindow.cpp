#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dados_jogador.h"
#include "loginform.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtDebug>

extern Dados_jogador pz;
extern QString estilo_normal;
extern QString estilo_404;
int mostra = 0;
int story = 0;
int diferente = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("/home/caio/Documentos/programacao/cheetah/first_gui_gp/cartas/c8.png");
    //ui->carta_8->setStyleSheet("border-image:url(/home/caio/Documentos/programacao/cheetah/first_gui_gp/cartas/c8.png);");
    ui->username->setText(pz.getNome());
    ui->subequipe->setText(pz.getSubequipeUsuario());
    this-> statusBar () -> hide ();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(temporizador()));
    timer->start(1000);
    ui->result_1->setVisible(false);
    ui->result_2->setVisible(false);
    ui->result_3->setVisible(false);
    ui->result_4->setVisible(false);
    ui->result_5->setVisible(false);
    ui->btn_backlog->setStyleSheet("border-image:url(:/new/prefix1/buttons/backlog_pressed.png);");
    reseta_carta();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::envia_sql(int carta)
{
    QString player = "jogador_";
    player += QString::number(pz.getJogador());
    //qDebug() << player;
    story = ui->edit_tarefa->text().toInt();

    QSqlQuery query;

    query.prepare("INSERT INTO "+pz.getPokerTable()+"_poker (story,"+player+","+player+"_confirma) VALUES (:story,:p1,:pc1) ON DUPLICATE KEY UPDATE "+player+" = :p1, "+player+"_confirma = :pc1");
    //query.bindValue(":player",player);
    query.bindValue(":p1",carta);
    query.bindValue(":pc1",1);
    query.bindValue(":story",story);
    query.exec();

    //qDebug() << query.executedQuery();
}

void MainWindow::atualiza()
{
    story = ui->edit_tarefa->text().toInt();
    //extern QSqlDatabase db;
    QSqlQuery query;
    query.prepare("SELECT * FROM "+pz.getPokerTable()+"_sprint WHERE story=:story");
    query.bindValue(":story",story);
    query.exec();
    while (query.next())
    {
        ui->label_tarefa->setText(query.value(1).toString());
        //qDebug() << query.value(0).toInt();
        //qDebug() << query.value(1).toString();
        //qDebug() << query.value(3).toInt();
    }
    //qDebug() << query.executedQuery();
}

void MainWindow::reseta_carta()
{
    ui->result_1->setStyleSheet("border-image:url(:/new/prefix1/cartas/card_back.png);");
    ui->result_2->setStyleSheet("border-image:url(:/new/prefix1/cartas/card_back.png);");
    ui->result_3->setStyleSheet("border-image:url(:/new/prefix1/cartas/card_back.png);");
    ui->result_4->setStyleSheet("border-image:url(:/new/prefix1/cartas/card_back.png);");
    ui->result_5->setStyleSheet("border-image:url(:/new/prefix1/cartas/card_back.png);");
}

void MainWindow::deleta_linha()
{
    QSqlQuery query;
    query.prepare("DELETE FROM "+pz.getPokerTable()+"_poker WHERE story="+QString::number(story)+"");
    query.exec();
}

void MainWindow::reseta_botoes()
{
    ui->btn_backlog->setStyleSheet("");
    ui->btn_dashboard->setStyleSheet("");
    ui->btn_kanban->setStyleSheet("");
    ui->btn_menu->setStyleSheet("");
    ui->btn_projeto->setStyleSheet("");
    ui->btn_anuncios->setStyleSheet("");
    ui->btn_sair->setStyleSheet("");
}

void MainWindow::erro404(int i)
{
    ui->centralwidget->setStyleSheet(i? estilo_normal : estilo_404);
    ui->edit_tarefa->setVisible(i);
    ui->label_alerta->setVisible(i);
    ui->label_pontuacao->setVisible(i);
    ui->label_pontuacao_2->setVisible(i);
    ui->label_tarefa->setVisible(i);
    ui->title->setVisible(i);
    ui->btn_proximo->setVisible(i);
    ui->btn_atualiza->setVisible(i);
    ui->carta_1->setVisible(i);
    ui->carta_2->setVisible(i);
    ui->carta_3->setVisible(i);
    ui->carta_5->setVisible(i);
    ui->carta_8->setVisible(i);
    ui->carta_13->setVisible(i);
    ui->carta_pi->setVisible(i);
    ui->carta_s->setVisible(i);
    ui->result_1->setVisible(i);
    ui->result_2->setVisible(i);
    ui->result_3->setVisible(i);
    ui->result_4->setVisible(i);
    ui->result_5->setVisible(i);
    reseta_botoes();
}

void MainWindow::on_btn_menu_clicked()
{
    erro404(0);
    ui->btn_menu->setStyleSheet("border-image:url(:/new/prefix1/buttons/menu_pressed.png);");
}


void MainWindow::on_btn_atualiza_clicked()
{
    atualiza();
}

void MainWindow::on_edit_tarefa_textChanged()
{

}

void MainWindow::on_carta_1_clicked()
{
    envia_sql(1);
}

void MainWindow::on_carta_2_clicked()
{
    envia_sql(2);
}

void MainWindow::on_carta_3_clicked()
{
    envia_sql(3);
}

void MainWindow::on_carta_5_clicked()
{
    envia_sql(5);
}

void MainWindow::on_carta_8_clicked()
{
    envia_sql(8);
}

void MainWindow::on_carta_13_clicked()
{
    envia_sql(13);
}

void MainWindow::on_carta_pi_clicked()
{
    envia_sql(314);
}

void MainWindow::on_carta_s_clicked()
{
    envia_sql(69);
}

void MainWindow::temporizador()
{
    QSqlQuery query;
    int r[20];
    memset(r,0,sizeof(r));

    query.prepare("SELECT * FROM "+pz.getPokerTable()+"_poker WHERE story=:story");
    query.bindValue(":story",story);
    query.exec();
    while (query.next())
    {
        int soma=0;
        for(int i = 2 ; i <= pz.getContagem()*2 ; i +=2)
        {
            soma += query.value(i).toInt();
            r[i] = query.value(i-1).toInt();
        }
        mostra = soma;
        /*qDebug() << query.value(0).toInt();
        qDebug() << query.value(1).toString();
        qDebug() << query.value(3).toInt();
        qDebug() <<mostra;*/
    }
    ui->result_1->setVisible((mostra > 0 ? true : false));
    ui->result_2->setVisible((mostra-1 > 0 ? true : false));
    ui->result_3->setVisible((mostra-2 > 0 ? true : false));
    ui->result_4->setVisible((mostra-3 > 0 ? true : false));
    ui->result_5->setVisible((mostra-4 > 0 ? true : false));

    if(mostra==pz.getContagem())
    {
        timer->stop();
        ui->result_1->setStyleSheet("border-image:url(:/new/prefix1/cartas/c"+QString::number(r[2])+".png);");
        ui->result_2->setStyleSheet("border-image:url(:/new/prefix1/cartas/c"+QString::number(r[4])+".png);");
        ui->result_3->setStyleSheet("border-image:url(:/new/prefix1/cartas/c"+QString::number(r[6])+".png);");
        ui->result_4->setStyleSheet("border-image:url(:/new/prefix1/cartas/c"+QString::number(r[8])+".png);");
        ui->result_5->setStyleSheet("border-image:url(:/new/prefix1/cartas/c"+QString::number(r[10])+".png);");
        diferente = 0;
        for(int i = 2 ; i <= (mostra*2)-2; i+=2)
        {
            if(r[i]!=r[i+2])
            {
                diferente = 1;
                break;
            }
        }

        if(diferente)
        {
            ui->label_alerta->setText("Notas diferentes, por favor aperte próximo para votar novamente!");
            QTimer::singleShot(2000, this, &MainWindow::deleta_linha);
        }
        else
        {
            query.prepare("UPDATE "+pz.getPokerTable()+"_sprint SET `pontuação`="+QString::number(r[2])+" WHERE story="+QString::number(story)+"");
            query.exec();

            query.prepare("SELECT * FROM "+pz.getPokerTable()+"_sprint WHERE story="+QString::number(story)+"");
            query.exec();
            while (query.next())
            {
                 ui->label_pontuacao->setText(query.value(3).toString());
                 qDebug() << query.value(3).toString();
            }
            qDebug() << query.executedQuery();
        }
    }

    qDebug() << pz.getContagem() << mostra <<r[2];
}

void MainWindow::on_btn_proximo_clicked()
{
    timer->start(1000);
    if(diferente)
    {
        ui->edit_tarefa->setText(QString::number(story));
    }
    else
    {
        ui->edit_tarefa->setText(QString::number(story+1));
    }
    atualiza();
    reseta_carta();
    mostra=0;
    ui->label_alerta->setText("");
    ui->label_pontuacao->setText("");
}

void MainWindow::on_btn_backlog_clicked()
{
    erro404(1);
    ui->btn_backlog->setStyleSheet("border-image:url(:/new/prefix1/buttons/backlog_pressed.png);");
}

void MainWindow::on_btn_dashboard_clicked()
{
    erro404(0);
    ui->btn_dashboard->setStyleSheet("border-image:url(:/new/prefix1/buttons/dashboard_pressed.png);");
}

void MainWindow::on_btn_kanban_clicked()
{
    erro404(0);
    ui->btn_kanban->setStyleSheet("border-image:url(:/new/prefix1/buttons/kanban_pressed.png);");
}

void MainWindow::on_btn_anuncios_clicked()
{
    erro404(0);
    ui->btn_anuncios->setStyleSheet("border-image:url(:/new/prefix1/images/splash.png);");
}

void MainWindow::on_btn_projeto_clicked()
{
    erro404(0);
    ui->btn_projeto->setStyleSheet("border-image:url(:/new/prefix1/buttons/projeto_pressed.png);");
}

void MainWindow::on_btn_sair_clicked()
{
    erro404(0);
    ui->btn_sair->setStyleSheet("border-image:url(:/new/prefix1/buttons/sair_pressed.png);");
}
