#pragma once
#include"stdafx.h"
#include"Menu.h"
#include "GerenciadorGrafico.h"
#include "MenuFases.h"
#include "MenuPause.h"
#include "MenuJogadores.h"

class MenuInicial :
	public Menu
{
private:
	sf::Text opcoes[3];
	MenuFases MFases;
	MenuPause MPause;
	MenuJogadores MJogadores;

public:
	MenuInicial(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
	~MenuInicial();
	void inicializarMenu();
	void desenhar();
	void moverCima();
	void moverBaixo();
	void executarEnter();
	Menu* getMenuPause();
	Menu* getMenuFases();
	Menu* getMenuJogadores();
};
