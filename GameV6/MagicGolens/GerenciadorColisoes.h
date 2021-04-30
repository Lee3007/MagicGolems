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

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	void adicionarEntidade(Entidade* e);
	void removerEntidade(Entidade* e);
	void esvaziar();
	void verificarColisoes();
	bool estaoColidindo(Entidade* e1, Entidade* e2);
};
