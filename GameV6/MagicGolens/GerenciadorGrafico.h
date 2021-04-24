#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Menu.h"

class Menu;
class GerenciadorEstado;

class GerenciadorGrafico
{
private:

	//Atributos
	GerenciadorEstado* GEstado;
	sf::RenderWindow janela;
	sf::Event evento;
	Menu *menu;
	ListaEntidades *LEntidades;

public:

	//Construtora e Destrutora
	GerenciadorGrafico();
	~GerenciadorGrafico();

	//Funcoes
	void desenhar();
	void limpar();
	void renderizar();
	void setGerenciador(GerenciadorEstado* Ge);
	void setListaEntidades(ListaEntidades* L);
	void setMenu(Menu* m);
	void fecharJanela();
	void setEvento();
	bool janelaExecutando();
	bool clickX();
};

