#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "sobre.h"
#include <QDir>
#include <QResource>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new QProcess();
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(updateSemaforo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    p->start("./sinal");
    ui->pushButton_4->setText("Fechar!");
    connect(ui->pushButton_4, SIGNAL(clicked()), SLOT(fechar()));
}

void MainWindow::updateSemaforo()
{
    QPixmap desligado(":/Images/desligado.png");
    QPixmap red(":/Images/red.png");
    QPixmap green(":/Images/green.png");
    QPixmap yellow(":/Images/yellow.png");
    QString string = (p->readAllStandardOutput());
    if (string.contains("Vermelho")) {
        ui->label_2->setPixmap(desligado);
        ui->label_3->setPixmap(desligado);
        ui->label->setPixmap(red);
    }
    else if (string.contains("Verde")) {
        ui->label->setPixmap(desligado);
        ui->label_2->setPixmap(desligado);
        ui->label_3->setPixmap(green);
    }
    else if (string.contains("Amarelo")) {
        ui->label->setPixmap(desligado);
        ui->label_3->setPixmap(desligado);
        ui->label_2->setPixmap(yellow);
    }
}

void MainWindow::fechar() {
    p->kill();
    close();
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
