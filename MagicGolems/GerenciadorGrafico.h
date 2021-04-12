#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"

class GerenciadorGrafico
{
private:

	//Atributos
	sf::RenderWindow janela;
	sf::Event evento;
	sf::Clock relogio;
	ListaEntidades *LEntidades;
	bool janelaAberta;

public:

	//Construtora e Destrutora
	GerenciadorGrafico();
	~GerenciadorGrafico();

	//Funcoes
	void desenhar();
	void limpar();
	void renderizar();
	void setListaEntidades(ListaEntidades* L);
	void fecharJanela();
	bool setEvento();
	bool janelaExecutando();
	bool fechouJanela();
	sf::Clock* getRelogio();
};

