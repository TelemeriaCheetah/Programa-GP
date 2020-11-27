#include "mainwindow.h"
#include "loginform.h"
#include <QSplashScreen>
#include <QTimer>
#include <QFile>
#include <QApplication>

QString estilo_normal;
QString estilo_404;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/new/prefix1/images/splash.png");
    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
    splash.show();
    loginForm w;
    //splash.showMessage("Loaded modules");

    QFile styleFile(":/new/prefix1/stylesheets/stylesheet.css");

    if(styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        estilo_normal = styleFile.readAll();
        a.setStyleSheet(estilo_normal);
    }
    styleFile.close();

    QFile es(":/new/prefix1/stylesheets/stylesheet_404.css");

    if(es.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        estilo_404 = es.readAll();
    }
    es.close();

    QTimer::singleShot(20, &splash, &QWidget::close); // keep displayed for 5 seconds
    QTimer::singleShot(20, &w, SLOT(show()));
    //w.show();

    return a.exec();
}
