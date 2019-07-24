#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::criarConects()
{
    connect(ui->actionNovo, SIGNAL(clicked()), this, SLOT(slotNovo()));
    connect(ui->actionAbrir, SIGNAL(clicked()), this, SLOT(slotAbrir()));
    connect(ui->actionSalvar, SIGNAL(clicked()), this, SLOT(slotSalvar()));
    connect(ui->actionDesfazer, SIGNAL(clicked()), this, SLOT(slotDesfazer()));
    connect(ui->actionCopiar, SIGNAL(clicked()), this, SLOT(slotCopiar()));
    connect(ui->actionColar, SIGNAL(clicked()), this, SLOT(slotColar()));
    connect(ui->actionRecortar, SIGNAL(clicked()), this, SLOT(slotRecortar()));
}

void slotNovo()
{

}
