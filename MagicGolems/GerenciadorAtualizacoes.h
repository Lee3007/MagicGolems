#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Entidade.h"

class GerenciadorAtualizacoes
{
private:
	ListaEntidades* LEntidades;

public:
	GerenciadorAtualizacoes();
	~GerenciadorAtualizacoes();
	void setListaEntidades(ListaEntidades* L);
	void atualizar(float t);
};

