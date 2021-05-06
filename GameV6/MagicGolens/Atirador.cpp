#include "stdafx.h"
#include "Atirador.h"

Atirador::Atirador(float t):
limite(t),
podeAtirar(false),
cooldown(0.f)
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
	if (Gc != NULL)
	{
		cout << "Gc recebido por um atirador" << endl;
		GColisoes = Gc;
	}
}

void Atirador::possoAtirar(float t)
{
	if (t >= limite)
	{
		podeAtirar = true;
	}
}
