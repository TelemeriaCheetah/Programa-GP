#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void temporizador();
private slots:
    void on_btn_menu_clicked();

    void on_edit_tarefa_textChanged();

    void on_btn_atualiza_clicked();

    void on_carta_1_clicked();

    void on_carta_2_clicked();

    void on_carta_3_clicked();

    void on_carta_5_clicked();

    void on_carta_8_clicked();

    void on_carta_13_clicked();

    void on_carta_pi_clicked();

    void on_carta_s_clicked();

    void on_btn_proximo_clicked();

    void on_btn_backlog_clicked();

    void on_btn_dashboard_clicked();

    void on_btn_kanban_clicked();

    void on_btn_anuncios_clicked();

    void on_btn_projeto_clicked();

    void on_btn_sair_clicked();

private:
    Ui::MainWindow *ui;
    void envia_sql(int carta);
    void atualiza();
    void reseta_carta();
    void deleta_linha();
    void reseta_botoes();
    void erro404(int i);
    QTimer *timer;
};
#endif // MAINWINDOW_H
