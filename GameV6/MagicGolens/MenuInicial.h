#pragma once
#include"stdafx.h"
#include"Menu.h"
#include "GerenciadorGrafico.h"
#include "MenuFases.h"
#include "MenuPause.h"

class MenuInicial:
	public Menu
{
private:
	sf::Text opcoes[3];
	MenuFases MFases;
	MenuPause MPause;

public:
	MenuInicial(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL);
	~MenuInicial();
	void inicializarMenu();
	void desenhar(sf::RenderWindow* j);
	void moverCima();
	void moverBaixo();
	void executarEnter();
	MenuPause* getMenuPause();
};
