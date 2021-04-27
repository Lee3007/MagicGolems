#include "stdafx.h"
#include "Menu.h"
#include "GerenciadorGrafico.h"

Menu::Menu(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground):
textura(),
background(),
fonte(),
itemSelecionado(0)
{
	GEstado = Ge;
	GGrafico = Gg;
	textura.loadFromFile(caminhoBackground);
	background.setTexture(textura);
	background.setScale(sf::Vector2f(2/3.f, 2/3.f));
}

Menu::~Menu()
{
}