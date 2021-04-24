#pragma once
#include "stdafx.h"
#include "GerenciadorEstado.h"

class GerenciadorGrafico;

class Menu
{
protected:
	sf::Font fonte;
	int itemSelecionado;
	GerenciadorGrafico* GGrafico;
	GerenciadorEstado* GEstado;

public:
	Menu(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL);
	~Menu();
	virtual void desenhar(sf::RenderWindow* j) = 0;
	virtual void moverCima() = 0;
	virtual void moverBaixo() = 0;
	virtual void executarEnter() = 0;
};

