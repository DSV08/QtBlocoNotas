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

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void printDebug();

private:
	Ui::MainWindow *ui;

	// Connects da Classe
	void criarConects();

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
void slotConfigurarPagina();
void slotImprimir();
void slotSair();


//
// menu Editar
//

void slotDesfazer();
void slotCopiar();
void slotColar();
void slotRecortar();
void slotExcluir();


//
// menu Ajuda
//
void slotSobre();


};

#endif // MAINWINDOW_H
