#include "stdafx.h"
#include "Atirador.h"

Atirador::Atirador()
{
	LEntidades = NULL;
	GColisoes = NULL;
}

Atirador::~Atirador()
{
	LEntidades = NULL;
}

void Atirador::setListaEntidades(ListaEntidades* lista)
{
	LEntidades = lista;
}

void Atirador::setGerenciadorColisoes(GerenciadorColisoes* Gc)
{
	GColisoes = Gc;
}
