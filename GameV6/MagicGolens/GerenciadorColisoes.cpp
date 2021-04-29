#include "stdafx.h"
#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(GerenciadorMapa* pg) :
pGm(pg)
{
	pTile = pGm->getTile();
	LEntidades = NULL;
}

GerenciadorColisoes::~GerenciadorColisoes() 
{
}

void GerenciadorColisoes::setListaEntidades(ListaEntidades* lista)
{
	LEntidades = lista;
}

bool GerenciadorColisoes::verificarColisoes() 
{
	
	return false;
}