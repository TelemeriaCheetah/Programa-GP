#ifndef ERRO404_H
#define ERRO404_H

#include <QMainWindow>

namespace Ui {
class erro404;
}

class erro404 : public QMainWindow
{
    Q_OBJECT

public:
    explicit erro404(QWidget *parent = nullptr);
    ~erro404();

private:
    Ui::erro404 *ui;
};

#endif // ERRO404_H
