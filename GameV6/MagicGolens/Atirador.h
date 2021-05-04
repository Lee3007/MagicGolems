#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

class Atirador
{
protected:
	GerenciadorColisoes* GColisoes;
	ListaEntidades* LEntidades;

public:
	Atirador();
	~Atirador();
	void setListaEntidades(ListaEntidades* lista);
	void setGerenciadorColisoes(GerenciadorColisoes* Gc);
};

