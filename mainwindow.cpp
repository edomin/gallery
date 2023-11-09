#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(Image& image, DirScroller& dir_scroller)
: QMainWindow()
, m_ui(new Ui::MainWindow)
, m_image(image)
, m_dir_scroller(dir_scroller) {
    m_ui->setupUi(this);
    QRegularExpression regex("-?([0-9][0-9]?|100)%?");
    m_le_brightness_validator =
        QSharedPointer<QRegularExpressionValidator>::create(regex, this);
    m_ui->leBrightness->setValidator(m_le_brightness_validator.data());
}

MainWindow::~MainWindow() {
    delete m_ui;
}

void MainWindow::on_pbOpen_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", ".",
     "Images (*.jpg *.png)");

    m_dir_scroller.open(fileName);
    m_image.load(m_dir_scroller.get_filename());
    m_ui->LblDisplay->setPixmap(m_image.get_pixmap());
    m_ui->HsBrightness->setValue(0);
    m_ui->leBrightness->setText("0%");
}


void MainWindow::on_pbPrev_clicked() {
    m_dir_scroller.prev();
    m_image.load(m_dir_scroller.get_filename());
    m_ui->LblDisplay->setPixmap(m_image.get_pixmap());
    m_ui->HsBrightness->setValue(0);
    m_ui->leBrightness->setText("0%");
}


void MainWindow::on_pbNext_clicked() {
    m_dir_scroller.next();
    m_image.load(m_dir_scroller.get_filename());
    m_ui->LblDisplay->setPixmap(m_image.get_pixmap());
    m_ui->HsBrightness->setValue(0);
    m_ui->leBrightness->setText("0%");
}

void MainWindow::on_HsBrightness_valueChanged(int value) {
    m_ui->leBrightness->setText(QString::number(value) + "%");
    m_image.set_brightness(value);
    m_ui->LblDisplay->setPixmap(m_image.get_pixmap());
}

void MainWindow::on_leBrightness_editingFinished() {
    m_ui->HsBrightness->setValue(
     m_ui->leBrightness->text().split("%")[0].toInt());
}


void MainWindow::on_pbQuit_clicked() {
    this->close();
}

