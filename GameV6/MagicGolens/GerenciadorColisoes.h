#pragma once
#include "stdafx.h"
#include <set>
#include "GerenciadorMapa.h"
#include "Entidade.h"
#include "ListaEntidades.h"

class GerenciadorColisoes
{
private:
	set<Entidade*> lista;
	GerenciadorMapa* GMapa;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	void setGerenciadorMapa(GerenciadorMapa* pGm);
	void adicionarEntidade(Entidade* e);
	void removerEntidade(Entidade* e);
	void esvaziar();
	void verificarColisoes();
	bool estaoColidindo(Entidade* e1, Entidade* e2);
};
