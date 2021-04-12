#pragma once
#include "stdafx.h"
#include "Entidade.h"

class ListaEntidades
{
private:

	//Atributos
	vector<Entidade*> lista;

public:

	//Construtora e Destrutora
	ListaEntidades();
	~ListaEntidades();

	//Funcoes
	void incluirEntidade(Entidade* e);
	void excluirEntidade(Entidade* e);
	int getTamanho();
	Entidade* operator[](int i);
};

