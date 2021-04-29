#pragma once
#include "stdafx.h"
#include "GerenciadorMapa.h"
#include "Entidade.h"
#include "ListaEntidades.h"

class GerenciadorColisoes
{
private:
	GerenciadorMapa* pGm;
	Tile* pTile;
	ListaEntidades* LEntidades;

public:
	GerenciadorColisoes(GerenciadorMapa* pg = NULL);
	~GerenciadorColisoes();
	void setListaEntidades(ListaEntidades* lista);
	bool verificarColisoes();
};
