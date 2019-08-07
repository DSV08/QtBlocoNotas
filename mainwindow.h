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
* Classe da janela principal. A interface que contém todas as funções do bloco de notas(abrir, salvar, etc)
*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

	/*!
	 *@brief Construtor 
	 *Construtor da Classe MainWindow
	 * @param parent Ponteiro para um Widget da janela principal
	 */
	explicit MainWindow(QWidget *parent = nullptr);


	/*!
	 * @brief Destrutor
	 * Destrutor da Classe MainWindow
	 */
	~MainWindow();


	 /*!
	 * @brief metodo teste para Debug
	 */
	void printDebug();


	/*!
	 * @brief Método Set.
	 * Método que guarda o caminho do arquivo que é editado
	 * @param arquivoCorrente Variavel com o caminho do arquivo que é editado.
	 * @return void
	 */
	void setArquivoCorrente(QString arquivoCorrente);


	/*!
	 * @brief Método Get.
	 * Método para obter o caminho do arquivo que é editado 
	 * @return QString retona o caminho do arquivo texto que esta em uso 
	 */
	QString getArquivoCorrente();


private:

	/*!
	 * @brief Ui
	 * objetos de interface do Qt
	 */
	Ui::MainWindow *ui;


	//Necessário?
	QFile arquivoCorrente;


	/*!
	 * @brief Criação dos conects
	 * Método para estabelecer a relação de acão e reação dos botões e suas funcionalidades 
	 */
	void criarConects();


	/*!
	* @brief Caminho do Arquivo em uso
	* Variavel global que armazena o caminho do arquivo que está sendo editado
	*/
	QString currentFileName;


	/*!
	 * @brief Dia da excecução
	 * Variavel para guardar o dia em que o programa foi excecutado
	 */
	QDateTime data;


	/*!
	 * @brief Hora da excecução
	 * Variavel para guardar a hora em que o programa foi excecutado
	 */
    QTime hora;
	

	/*!
	 * @brief Limpar a interface
	 * Método para resetar as configurações do bloco de notas(caminho do arquivo em uso, título do bloco, etc)
	 * dando assim um clean na interface
	 *@return bool Retorna verdade se foi possivel limpar a interface com sucesso
	 */
	bool limparInterface();


	/*!
	 * @brief Salvar
	 * Método para salvar o texto do bloco de notas em um arquivo em uso ou em um novo arquivo
	 *  que será criado caso não tenha um arquivo em uso
	 */
	//metodo para salvar os tipos de arquivo conforme escolhido pelo usuario, chamdo pelo slot save
	void salvarArquivo();


	/*!
	*@brief Mensagem de status
	*Método que exibi uma mensagem na barra de status informando se uma determinada 
	*operação foi realizada com sucesso
	*@param msgs Messagem que será escrita na barra de status
	*/
	void escreverBarraStatus(QString msgs);


	/*!
	*@brief Título
	*Método para setar como título do bloco de notas o nome do arquivo em uso
	*ou uma mensagem vazia caso o arquivo esteja sendo construido
	*@param msg Mensagem com o nome do arquivo que será construido.
	*/
	void escreveTituloJanelaPrincipal(QString msg = "");


	/*!
	*@brief Configuração da página
	*Variavel que aponta para uma janela de propriedades da página
	*/
	QPageSetupDialog *pageprop;


	/*!
	*@brief imprimir página
	*Variavel que aponta para uma janela de propriedades para imprimir uma página
	*/
	QPrintDialog *paginaImprimir;


	/*!
	*@brief Visualizar página
	*Variavel que aponta para uma janela de propriedades para visualizar uma página
	*/
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
