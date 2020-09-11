#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(unsigned(QTime::currentTime().msec()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_Timer_tick()));
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_HuntedButton_clicked()
{
    if(!timer.isActive())
    {
        time.start();
        timer.start(100);
    }
    int w = ui->HuntedButton->width();
    int h = ui->HuntedButton->height();
    int x = ui->centralwidget->width() - w;
    int y = ui->centralwidget->height() - h;
    ui->HuntedButton->setGeometry(qrand() % x, qrand() % y, w, h);
    ++score;
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec");
}

void MainWindow::on_Timer_tick()
{
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec");
}

void MainWindow::closeEvent(QCloseEvent *)
{
    timer.stop();
    int millisec = time.elapsed();
    time.~QTime();
    QMessageBox msgBox;
    msgBox.setText("Pushes per seconds: " + QString::number(double(score) * 1000 / millisec,'f',2));
    msgBox.exec();
}
