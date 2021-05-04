#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"

class ListaEntidades
{
private:

	//Atributos
	//vector<Entidade*> lista;
	Lista<Entidade> lista;
	int tam;

public:

	//Construtora e Destrutora
	ListaEntidades();
	~ListaEntidades();

	//Funcoes
	void incluirEntidade(Entidade* e);
	void removerEntidade(Entidade* e);
	void esvaziar();
	void destruirEntidades();
	void atualizar();
	void desenhar();
	void colidir();
	bool getVaziaStatus();
	int getTamanho() const;
};
