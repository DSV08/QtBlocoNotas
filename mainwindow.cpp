#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
	this->ui->setupUi(this);

	//chamada dos connects do QT
	this->criarConects();
}

MainWindow::~MainWindow()
{
	delete this->ui;
}

void MainWindow::printDebug()
{
	qDebug() << "oi passei por aqui" << endl;
}

void MainWindow::criarConects()
{
	/* menu Arquivo*/
	connect(ui->actionNovo,              SIGNAL(triggered()), this, SLOT(slotNovo()));
	connect(ui->actionAbrir,             SIGNAL(triggered()), this, SLOT(slotAbrir()));
	connect(ui->actionSalvar,            SIGNAL(triggered()), this, SLOT(slotSalvar()));
	connect(ui->actionSalvarComo,        SIGNAL(triggered()), this, SLOT(slotSalvarComo()));
	connect(ui->actionConfigurarPagina,  SIGNAL(triggered()), this, SLOT(slotConfigurarPagina()));
	connect(ui->actionImprimir,          SIGNAL(triggered()), this, SLOT(slotImprimir()));
	connect(ui->actionSair,              SIGNAL(triggered()), this, SLOT(slotSair()));
	

	/* menu Editar*/
	connect(ui->actionDesfazer, SIGNAL(triggered()), this, SLOT(slotDesfazer()));
	connect(ui->actionCopiar,   SIGNAL(triggered()), this, SLOT(slotCopiar()));
	connect(ui->actionColar,    SIGNAL(triggered()), this, SLOT(slotColar()));
	connect(ui->actionRecortar, SIGNAL(triggered()), this, SLOT(slotRecortar()));
	connect(ui->actionExcluir,  SIGNAL(triggered()), this, SLOT(slotExcluir()));

	/* menu Formatar*/


	/* menu Exibir*/


	/* menu Ajuda*/
	connect(ui->actionSobre, SIGNAL(triggered()), this, SLOT(slotSobre()));



}


//
// menu Arquivo
//

void MainWindow::slotAbrir()
{

}

//metodo para salvar um arquivo ascii do bloco de notas
void MainWindow::slotSalvar()
{
	//perguntado ao usuario onde ele quer salvar o arquivo
	QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Arquivo"), QDir::homePath() , tr("Texto (*.txt)"));

	//Criar Um Arquivo Texto
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
		return;
	else {

		QTextStream out(&file);
		out << this->ui->textEdit->toPlainText();

		// optional, as QFile destructor will already do it:
		file.close();

	}

}

void MainWindow::slotSalvarComo()
{
}

void MainWindow::slotConfigurarPagina()
{
}

void MainWindow::slotImprimir()
{
}

void MainWindow::slotSair()
{
	qApp->quit();
}


//
// menu Editar
//


void MainWindow::slotDesfazer()
{
}

void MainWindow::slotCopiar()
{
}

void MainWindow::slotColar()
{
}

void MainWindow::slotRecortar()
{
}

void MainWindow::slotExcluir()
{
}

void MainWindow::slotSobre()
{
}

void MainWindow::slotNovo()
{
	this->printDebug();
}


