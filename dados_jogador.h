#ifndef DADOS_JOGADOR_H
#define DADOS_JOGADOR_H

#include <QMainWindow>
#include <QTimer>

class Dados_jogador
{
private:
    int jogador;
    int cont;
    QString nome;
    QString nick;
    QString subequipe;
    QString poker_table;
public:
    Dados_jogador();
    void setJogador(int);
    int getJogador();
    QString getNome();
    void setNome(QString a);
    QString getNick();
    void setNick(QString a);
    QString getSubequipe();
    void setSubequipe(QString a);
    QString getPokerTable();
    void setPokerTable(QString a);
    void setContagem(int a);
    int getContagem();
    QString getSubequipeUsuario();
};

#endif // DADOS_JOGADOR_H
