#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QProcess *p;

private slots:
    void on_pushButton_4_clicked();
    void updateSemaforo();
    void fechar();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
