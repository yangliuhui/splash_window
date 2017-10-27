#include "mainwindow.h"
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include <QPixmap>
#include <QSplashScreen>
#include <QDir>
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix(QDir("giphy.gif").absolutePath());
    QSplashScreen splash(pix);

    QLabel label(&splash);
    QMovie mv(QDir("giphy.gif").absolutePath());
    label.setMovie(&mv);
    mv.start();
    splash.show();
    splash.setCursor(Qt::BlankCursor);
    for (int i = 0; i < 5000; i += mv.speed()) {
        QCoreApplication::processEvents();
        QThread::usleep(mv.speed() * 1000);
    }
    MainWindow w;
    w.show();
    splash.finish(&w);	// 启动后关闭动画
    return a.exec();
}
