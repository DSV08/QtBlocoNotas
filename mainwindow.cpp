#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
	this->ui->setupUi(this);

	//chamada dos connects do QT
	this->criarConects();

	//inicializando o nome da janela principal
	this->escreveTituloJanelaPrincipal();

	this->pageprop = new QPageSetupDialog();
	//this->pageprop->exec();

	this->paginaImprimir = new QPrintDialog;

}

MainWindow::~MainWindow()
{
	delete this->ui;
}

void MainWindow::printDebug()
{
	qDebug() << "oi passei por aqui" << endl;
}

void MainWindow::setArquivoCorrente(QString arquivoCorrente)
{
	this->currentFileName = arquivoCorrente;
}

QString MainWindow::getArquivoCorrente()
{
	return this->currentFileName;
}

void MainWindow::criarConects()
{
	/* menu Arquivo*/
	connect(ui->actionNovo,                SIGNAL(triggered()), this, SLOT(slotNovo()));
	connect(ui->actionAbrir,               SIGNAL(triggered()), this, SLOT(slotAbrir()));
	connect(ui->actionSalvar,              SIGNAL(triggered()), this, SLOT(slotSalvar()));
	connect(ui->actionSalvarComo,          SIGNAL(triggered()), this, SLOT(slotSalvarComo()));
	connect(ui->actionConfigurarPagina,    SIGNAL(triggered()), this, SLOT(slotConfigurarPagina()));
	connect(ui->actionVisualizarImpressao, SIGNAL(triggered()), this, SLOT(slotVisualizarImpressao()));
	connect(ui->actionImprimir,            SIGNAL(triggered()), this, SLOT(slotImprimir()));
	connect(ui->actionSair,                SIGNAL(triggered()), this, SLOT(slotSair()));
	

	/* menu Editar*/
	connect(ui->actionDesfazer, SIGNAL(triggered()), this, SLOT(slotDesfazer()));
	connect(ui->actionRefazer,  SIGNAL(triggered()), this, SLOT(slotRefazer()));
	connect(ui->actionCopiar,   SIGNAL(triggered()), this, SLOT(slotCopiar()));
	connect(ui->actionColar,    SIGNAL(triggered()), this, SLOT(slotColar()));
	connect(ui->actionRecortar, SIGNAL(triggered()), this, SLOT(slotRecortar()));
	connect(ui->actionExcluir,  SIGNAL(triggered()), this, SLOT(slotExcluir()));

	/* menu Formatar*/
	

	/* menu Exibir*/


	/* menu Ajuda*/
	connect(ui->actionSobre, SIGNAL(triggered()), this, SLOT(slotSobre()));



}

bool MainWindow::limparInterface()
{
	this->ui->textEdit->clear();
	return false;

	this->currentFileName.clear();
	this->escreveTituloJanelaPrincipal();
}

void MainWindow::salvarArquivo()
{
	//Criar Um Arquivo 
	QFileInfo tipoArquivo(this->getArquivoCorrente());
	QFile arquivo(this->getArquivoCorrente());
	QString ext = tipoArquivo.suffix();  // ext = "gz"

										 //se o arquivo for txt
	if (ext.compare("txt") == 0)
	{
		this->slotSalvarTXT(this->getArquivoCorrente(), this->ui->textEdit->toPlainText());

	}
	else //se o arquivo for pdf
	{

		this->slotSalvarPDF(this->getArquivoCorrente(), this->ui->textEdit->toPlainText());
	}
}

void MainWindow::escreverBarraStatus(QString msgs)
{
	this->statusBar()->clearMessage();
	this->statusBar()->showMessage(msgs, 5000);
}

void MainWindow::escreveTituloJanelaPrincipal(QString msg)
{

	//concatenado Strings
	msg.append(" - ");
	msg.append("Bloco de Notas");

	//trocar o titulo da janele principal
	this->setWindowTitle(msg);

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
	
	//verificando se a variavel global armazenamento do caminho do arquivo existe
	if (this->getArquivoCorrente().isEmpty())
	{
		//perguntado ao usuario onde ele quer salvar o arquivo
		QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Arquivo"), QDir::homePath(), tr("Texto (*.txt) ;; PDF (*.pdf)"));

		if (!fileName.isEmpty()) {
			this->setArquivoCorrente(fileName);

			//chamando o metodo de salvar o arquivo 
			this->salvarArquivo();
		}
		else
		{
			return;
		}
	}
	else {

		//chamando o metodo de salvar o arquivo 
		this->salvarArquivo();
	}
	
	

	//Atribuindo o nome do arquivo no titulo da janela principal
	QString shortFileName = QFileInfo(this->getArquivoCorrente()).fileName();
	this->escreveTituloJanelaPrincipal(shortFileName);
	


}

void MainWindow::slotSalvarComo()
{
	//perguntado ao usuario onde ele quer salvar o arquivo
	QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Arquivo"), QDir::homePath() ,  tr("Text files (*.txt)"));

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
	this->pageprop->exec();
}

void MainWindow::slotVisualizarImpressao()
{
	this->paginaVisualizar = new QPrintPreviewDialog();
	this->paginaVisualizar->exec();
}

void MainWindow::slotImprimir()
{
	this->paginaImprimir->exec();
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

void MainWindow::slotRefazer()
{
	this->ui->textEdit->redo();
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
	
}

void MainWindow::slotSobre()
{

}

//Salvar o conteudo da interface em PDF
void MainWindow::slotSalvarPDF(QString fileName, QString text)
{
	QPrinter printer;
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setOutputFileName(fileName);
	
	QPainter painter;
	if (!painter.begin(&printer)) { // failed to open file
		qWarning("failed to open file, is it writable?");
		return;
	}
	
	painter.drawText(10, 10, text);
	
	/*if (!printer.newPage()) {
		qWarning("failed in flushing page to disk, disk full?");
		return;
	}
	painter.drawText(10, 10, "Test 2");*/
	painter.end();

	QString shortFileName = QFileInfo(this->getArquivoCorrente()).fileName();
	this->escreverBarraStatus("O Arquivo " + shortFileName + " foi salvo com sucesso");
}

void MainWindow::slotSalvarTXT(QString fileName, QString text)
{
	// criando um arquivo TXT
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	else {

		QTextStream out(&file);
		out << text;

		// optional, as QFile destructor will already do it:
		file.close();


		//escrendo uma mensagem de que terminou de salvar
		QString shortFileName = QFileInfo(file).fileName();
		this->escreverBarraStatus("O Arquivo " + shortFileName + " foi salvo com sucesso");
	}
}


void MainWindow::slotNovo()
{
	this->ui->textEdit->clear();
}


