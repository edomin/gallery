#include "dirscroller.h"
#include "image.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Image        image;
    DirScroller  dirscroller;
    MainWindow   window(image, dirscroller);

    window.show();
    return app.exec();
}
