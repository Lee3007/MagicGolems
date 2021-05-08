#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

class Atirador
{
protected:
	float limite;
	float cooldown;
	bool podeAtirar;
	GerenciadorColisoes* GColisoes;
	ListaEntidades* LEntidades;

public:
	Atirador(float t = 1);
	~Atirador();
	void setListaEntidades(ListaEntidades* lista);
	void setGerenciadorColisoes(GerenciadorColisoes* Gc);
	virtual void salvar() = 0;
	virtual void carregar() = 0;
	void possoAtirar(float t);
};

