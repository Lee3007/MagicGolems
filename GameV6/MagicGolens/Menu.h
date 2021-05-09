#pragma once
#include "stdafx.h"
#include "GerenciadorEstado.h"

class GerenciadorGrafico;

class Menu
{
protected:
	sf::Font fonte;
	sf::Texture textura;
	sf::Sprite background;
	int itemSelecionado;
	GerenciadorGrafico* GGrafico;
	GerenciadorEstado* GEstado;
	sf::RenderWindow* janela;

public:
	Menu(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
	~Menu();
	virtual void desenhar() = 0;
	virtual void moverCima() = 0;
	virtual void moverBaixo() = 0;
	virtual void executarEnter() = 0;
	virtual void atualizar(sf::Event evento);
};
