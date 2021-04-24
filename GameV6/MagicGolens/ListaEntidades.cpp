#include "stdafx.h"
#include "ListaEntidades.h"

//Construtora e Destrutora

ListaEntidades::ListaEntidades():
LEntidades()
{
}

ListaEntidades::~ListaEntidades()
{

}

//Funcoes

void ListaEntidades::incluirEntidade(Entidade* e)
{
	LEntidades.incluirInfo(e);
}

void ListaEntidades::excluirEntidade(Entidade* e)
{
	LEntidades.excluirInfo(e);
}

int ListaEntidades::getTamanho()
{
	return LEntidades.getTamanho();
}

Entidade* ListaEntidades::operator[](int i)
{
	return LEntidades.getInfo(i);
}
