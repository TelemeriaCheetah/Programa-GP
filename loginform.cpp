#include "loginform.h"
#include "ui_loginform.h"
#include "dados_jogador.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtDebug>


Dados_jogador pz;
int teste;

loginForm::loginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.0.238");
    //db.setHostName("gerenciamento.cheetah.caiobc.com");
    db.setDatabaseName("qt_teste");
    db.setUserName("caio");
    db.setPassword("illusion geek");
    bool ok = db.open();
    if(ok)
    {
        ui->debug_gambiarra->setText("debug: DEU BOM");
    }
    else
    {
        ui->debug_gambiarra->setText("debug: DEU RUIM");
        //qDebug() << db.lastError().text();
    }
    ui->password->setEchoMode(QLineEdit::Password);
}

loginForm::~loginForm()
{
    delete ui;
}

void loginForm::on_btn_login_clicked()
{
    pz.setJogador(-1);
    QString username = ui->username->text();
    QString password = ui->password->text();
    if(password=="gerenciamento")
    {
        qDebug() << username;
        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE nick=:user");
        query.bindValue(":user",username);
        query.exec();
        while (query.next())
        {
            pz.setJogador(query.value(0).toInt());
            pz.setNick(query.value(1).toString());
            pz.setNome(query.value(2).toString());
            pz.setSubequipe(query.value(3).toString());
            pz.setPokerTable(query.value(3).toString());

            ui->debug_gambiarra->setText(QString::number(pz.getJogador()));
            hide();
            mainWindow = new MainWindow(this);
            mainWindow -> show();
        }

        query.prepare("SELECT * FROM user_count WHERE subequipe=:user");
        query.bindValue(":user",pz.getPokerTable());
        query.exec();
        while (query.next())
        {
            pz.setContagem(query.value(2).toInt());
            qDebug() << pz.getContagem();
        }


        if(pz.getJogador()==-1)
        {
            ui->debug_gambiarra->setText("debug: USUARIO INVALIDO");
        }
    }
    else
        ui->debug_gambiarra->setText("debug: ERROU A SENHA HEIN");
}
