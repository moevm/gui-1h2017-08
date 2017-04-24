#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GameFiels->hide();
    this->setGeometry(100,100,1000,600);

}

MainWindow::~MainWindow()
{
    delete ui;
}
