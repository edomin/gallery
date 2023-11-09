#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

#include "dirscroller.h"
#include "image.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Image& image, DirScroller& dir_scroller);
    ~MainWindow();

private slots:
    void on_pbOpen_clicked();

    void on_pbPrev_clicked();

    void on_pbNext_clicked();

    void on_HsBrightness_valueChanged(int value);

    void on_leBrightness_editingFinished();

    void on_pbQuit_clicked();

private:
    Ui::MainWindow            *m_ui;
    Image&                     m_image;
    DirScroller&               m_dir_scroller;
    QSharedPointer<QValidator> m_le_brightness_validator;
};
#endif // MAINWINDOW_H
