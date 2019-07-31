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
   //Pegando o arquivo que será aberto
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("Texto (*.txt)"));

   //Exibindo o arquivo que será aberto no textEdit
   QFile file(fileName);
   if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
       return;
   else
   {
       QTextStream in(&file);
       while(!in.atEnd())
       {
           this->ui->textEdit->append(in.readLine());
       }
       file.close();
   }
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
    //perguntado ao usuario onde ele quer salvar o arquivo
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Arquivo"), QDir::homePath() ,
                                                    tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;"
                                                       "XML files (*.xml)"));

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
    this->ui->textEdit->undo();
}

void MainWindow::slotCopiar()
{
    this->ui->textEdit->copy();
}

void MainWindow::slotColar()
{
    this->ui->textEdit->paste();
}

void MainWindow::slotRecortar()
{
    this->ui->textEdit->cut();
}

void MainWindow::slotExcluir()
{
    //this->ui->textEdit->clear();
}

void MainWindow::slotSobre()
{
}

void MainWindow::slotNovo()
{
    //this->printDebug();
    this->ui->textEdit->clear();
}


