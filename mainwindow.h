#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <cstdio>
#include <stdio.h>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPainter>
#include <QPageSetupDialog>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QMessageBox>
#include <QDateTime>

using namespace std;

namespace Ui {
class MainWindow;
}


/** A Test class.
*  More details about this class.
*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	 /*!
	 * @brief metodo teste para Debug
	 */
	void printDebug();

	//metodo set para a variavel arquivo corrente
	void setArquivoCorrente(QString arquivoCorrente);

	//metodo get para a variavel arquivo corrente
	QString getArquivoCorrente();

private:
	//objetos de interface do Qt
	Ui::MainWindow *ui;

	//Variavel com o arquivo que está sendo excecutado
	QFile arquivoCorrente;

	// Connects da Classe
	void criarConects();

	//variavel para o armazenamento do caminho do arquivo
	QString currentFileName;

	//variavel para armazenar a data da excucao do programa
	QDateTime data;
	
	//metodo responsavel pode realizar um clean na interface. 
	bool limparInterface();

	//metodo para salvar os tipos de arquivo conforme escolhido pelo usuario, chamdo pelo slot save
	void salvarArquivo();

	//metodo para escrever uma mensagem na barra de status
	void escreverBarraStatus(QString msgs);

	//Atribuindo o nome do arquivo no titulo da janela principal
	void escreveTituloJanelaPrincipal(QString msg = "");


	//Teste janela propriedade da pagina 
	QPageSetupDialog *pageprop;

	QPrintDialog *paginaImprimir;

	QPrintPreviewDialog *paginaVisualizar;




private slots:

//
// menu Arquivo
//

//slot novo arquivo
void slotNovo();

//slot para abrir um arquivo
void slotAbrir();

//slot para salvar um arquivo
void slotSalvar();

void slotSalvarComo();
void slotVisualizarImpressao();
void slotConfigurarPagina();
void slotImprimir();
void slotSair();

void printPreview(QPrinter *printer);


//
// menu Editar
//

void slotDesfazer();
void slotRefazer();
void slotCopiar();
void slotColar();
void slotRecortar();
void slotExcluir();


//
// menu Ajuda
//
void slotSobre();


void slotSalvarPDF(QString filename, QString text);
void slotSalvarTXT(QString filename, QString text);

};

#endif // MAINWINDOW_H
