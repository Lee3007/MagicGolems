#include "stdafx.h"
#include "Menu.h"
#include "GerenciadorGrafico.h"

Menu::Menu(GerenciadorEstado* Ge, GerenciadorGrafico* Gg):
fonte(),
itemSelecionado(0)
{
	GEstado = Ge;
	GGrafico = Gg;
}

Menu::~Menu()
{
}