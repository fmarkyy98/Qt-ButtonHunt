#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTime"
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_HuntedButton_clicked();
    void on_Timer_tick();

private:
    Ui::MainWindow *ui;
    int score = 0;
    QTime time;
    QTimer timer;
    void closeEvent(QCloseEvent *) override;
};
#endif // MAINWINDOW_H
