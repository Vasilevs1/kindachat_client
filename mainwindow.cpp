#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    socket=new QTcpSocket(this);
    ui->setupUi(this);
    connect(ui->hostEdit,SIGNAL(returnPressed()),this,SLOT(connecttoServer()));
    connect(ui->connectButton,SIGNAL(clicked(bool)),this,SLOT(connecttoServer()));
    connect(socket,SIGNAL(connected()),this,SLOT(connectedtoServer()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connecttoServer()
{
    socket->connectToHost(ui->hostEdit->text(),12000);
}

void MainWindow::connectedtoServer()
{
    ui->statusLabel->setText("STATUS:ONLINE");
}

void MainWindow::error(QAbstractSocket::SocketError)
{
    ui->statusLabel->setText("STATUS:"+socket->errorString());
}
