#include "stdafx.h"
#include "ListaEntidades.h"

//Construtora e Destrutora

ListaEntidades::ListaEntidades():
lista(),
tam(0)
{
}

ListaEntidades::~ListaEntidades()
{

}

//Funcoes

void ListaEntidades::incluirEntidade(Entidade* e)
{
	lista.incluirInfo(e);
	tam++;
}

void ListaEntidades::removerEntidade(Entidade* e)
{
	lista.removerInfo(e);
	tam--;
}

void ListaEntidades::esvaziar()
{
	lista.esvaziar();
}

void ListaEntidades::destruirEntidades()
{
	Entidade* e = lista.voltarInicio();

	while (e != NULL)
	{
		if (e == NULL)
		{
			cout << "ERRO: Tentando deletar ponteiro NULL" << endl;
			exit(980);
		}

		delete e;
		e = lista.irProximo();
	}

	lista.esvaziar();
	tam = 0;
}

void ListaEntidades::atualizar()
{
	Entidade* e = lista.voltarInicio();

	while (e != NULL)
	{
		e->atualizar();
		e = lista.irProximo();
	}
}

void ListaEntidades::desenhar( )
{
	Entidade* e = lista.voltarInicio();

	while (e != NULL)
	{
		e->desenhar();
		e = lista.irProximo();
	}
}

bool ListaEntidades::getVaziaStatus()
{
	if(tam > 0)
		return false;

	return true;
}

int ListaEntidades::getTamanho() const
{
	return tam;
}
