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

/*!
 * @brief Slot novo
 * Esse slot é excecutado quando a opção novo é escolhida, resetando o bloco de notas e 
 * preparando para criar um novo arquivo
 */
void slotNovo();


/*!
 * @brief Slot abrir
 * Esse slot é excecutado quando a opção abrir é escolhida, permitindo ao usuario escolher um arquivo
 * que será aberto para editar, salvar, etc. 
 * 
 */
void slotAbrir();


/*!
 * @brief Slot Salvar
 * Esse slot é excecutado quando a opção salvar é escolhida, permitindo que a alteração feita no texto seja salva
 * ou crie um arquivo caso o texto esteja sendo criado pela primeira vez
 */
void slotSalvar();


/*!
 * @brief Slot salvar como
 * Esse slot é excecutado quando a opção salvar é escolhida, permitindo que o usuário salve um novo arquivo a partir 
 * de um arquivo que já estava sendo editado e não altere o arquivo que estava em uso.
 */
void slotSalvarComo();


/*!
 * @brief Slot visualizar impressão
 * Esse slot é excecutado quando a opção visualizar impressão é escolhida, abrindo uma tela em que é possível 
 * visualizar como ficaria a impressão da página
 */
void slotVisualizarImpressao();


/*!
 * @brief Slot configurar página
 * Esse slot é excecutado quando a opção configurar página é escolhida,abrindo uma tela que permite alterar 
 * algumas configurações da página
 */
void slotConfigurarPagina();


/*!
 * @brief Slot imprimir
 * Esse slot é excecutado quando a opção imprimir é escolhida, abrindo uma tela com as opções para imprimir
 * a página
 */
void slotImprimir();


/*!
 * @brief Slot sair
 * Esse slot é excecutado quando a opção sair é escolhida, fechando o bloco de notas
 */
void slotSair();


/*!
 * @brief printpreview
 * Esse  Método é utilizado para exibir uma tela com a visualização do texto 
 * @param printer Print para a utilização do método
 */
void printPreview(QPrinter *printer);


//
// menu Editar
//



/*!
 * @brief Slot desfazer
 * Esse slot é excecutado quando a opção desfazer é escolhida, desfazendo a última modificação feita no texto 
 */
void slotDesfazer();


/*!
* @brief Slot refazer
* Esse slot é excecutado quando a opção refazer é escolhida, refazendo a última modificação feita no texto
*/
void slotRefazer();


/*!
* @brief Slot copiar
* Esse slot é excecutado quando a opção copiar é escolhida, que copia o texto selecionado
*/
void slotCopiar();


/*!
* @brief Slot colar
* Esse slot é excecutado quando a opção colar é escolhida, colando no texto um texto anteriormente copiado ou recortado
*/
void slotColar();


/*!
* @brief Slot recortar
* Esse slot é excecutado quando a opção recortar é escolhida, copiando um texto selecionado e deletando o texto que foi selecionado
*/
void slotRecortar();


/*!
* @brief Slot excluir
* Esse slot é excecutado quando a opção excluir é escolhida, excluindo o texto selecionado
*/
void slotExcluir();


//
// menu Ajuda
//



/*!
* @brief Slot sobre
* Esse slot é excecutado quando a opção sobre é escolhida, abrindo uma tela com informações sobre 
* autor data e hora da excecução do bloco de notas
*/
void slotSobre();


/*!
* @brief Slot salvar em pdf
* Esse slot é excecutado quando a opção salvar ou salvar como é escolhida, possibilitando que o arquivo possa ser salvo em pdf
* @param filename Nome do arquivo que será salvo
* @param text Texto no bloco de notas do arquivo que será salvo
*/
void slotSalvarPDF(QString filename, QString text);


/*!
* @brief Slot salvar em txt
* Esse slot é excecutado quando a opção salvar ou salvar como é escolhida, possibilitando que o arquivo possa ser salvo em txt
* @param filename Nome do arquivo que será salvo
* @param text Texto no bloco de notas do arquivo que será salvo
*/
void slotSalvarTXT(QString filename, QString text);

};

#endif // MAINWINDOW_H
