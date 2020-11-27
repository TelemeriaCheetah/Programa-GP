#include "dados_jogador.h"
#include <QtDebug>
Dados_jogador::Dados_jogador()
{

}

void Dados_jogador::setJogador(int a)
{
    jogador = a;
}

int Dados_jogador::getJogador()
{
    return jogador;
}

void Dados_jogador::setNome(QString a)
{
    nome = a;
}

void Dados_jogador::setNick(QString a)
{
    nick = a;
}

QString Dados_jogador::getNome()
{
    return nome;
}

QString Dados_jogador::getNick()
{
    return nick;
}

QString Dados_jogador::getSubequipe()
{
    return subequipe;
}

void Dados_jogador::setSubequipe(QString a)
{
    subequipe = a;
}

QString Dados_jogador::getPokerTable()
{
    return poker_table;
}

void Dados_jogador::setPokerTable(QString a)
{
    poker_table = a;
}

void Dados_jogador::setContagem(int a)
{
    cont = a;
}

int Dados_jogador::getContagem()
{
    return cont;
}

QString Dados_jogador::getSubequipeUsuario()
{
    if(subequipe=="elt")
        return "Eletrônica";
    else if(subequipe=="est")
        return "Estrutura";
    else if(subequipe=="pwt")
        return "Powertrain";
}


