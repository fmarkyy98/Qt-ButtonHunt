#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(unsigned(QTime::currentTime().msec())); // Give the qrand a seed of current milisecond.
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_Timer_tick())); // connecting the Timers timeour (Tic) event to the on_Timer_tic evenhandler.
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec"); // Some UI statusbar design.
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_HuntedButton_clicked()
{
    if(!timer.isActive())  // Starting the time, and the time, on the
    {                      // on the wery first click event, but not
        time.start();      // on the other clicks.
        timer.start(100);  //
    }
    int w = ui->HuntedButton->width();                              //
    int h = ui->HuntedButton->height();                             //
    int x = ui->centralwidget->width() - w;                         // Next position calculation.
    int y = ui->centralwidget->height() - h;                        //
    ui->HuntedButton->setGeometry(qrand() % x, qrand() % y, w, h);  //
    ++score;
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec"); // UI statusbar design update on click event.
}

void MainWindow::on_Timer_tick()
{
    ui->statusbar->showMessage("Points: " + QString::number(score) + " | Elapsed time: "+QString::number(time.elapsed()/1000)+" sec"); // UI statusbar design update on Tic event.
}

void MainWindow::closeEvent(QCloseEvent *)
{
    timer.stop();                   //
    int millisec = time.elapsed();  // Freez the moment in spacetime.
    time.~QTime();                  //
    QMessageBox msgBox;                                                                               //
    msgBox.setText("Pushes per seconds: " + QString::number(double(score) * 1000 / millisec,'f',2));  // Showing messagebox,
    msgBox.exec();                                                                                    // with the right parameters.
}
