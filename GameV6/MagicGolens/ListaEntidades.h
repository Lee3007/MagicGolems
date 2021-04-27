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
	void atualizar(float t);
	void desenhar(sf::RenderWindow* j);
	bool getVaziaStatus();
	int getTamanho() const;
};

