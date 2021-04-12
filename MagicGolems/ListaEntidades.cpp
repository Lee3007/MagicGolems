#include "stdafx.h"
#include "ListaEntidades.h"

//Construtora e Destrutora

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
	vector<Entidade*>::const_iterator iterador;
	iterador = lista.begin();
	Entidade* pEntidade = NULL;

	while (iterador != lista.end())
	{
		pEntidade = *iterador;
		delete pEntidade;
		iterador++;
	}

	lista.clear();
	pEntidade = NULL;
}

//Funcoes

void ListaEntidades::incluirEntidade(Entidade* e)
{
	if (e != NULL)
	{
		lista.push_back(e);
	}
	else
		cout << "ERRO: Nao foi possivel inserir entidade na lista" << endl;
}

void ListaEntidades::excluirEntidade(Entidade* e)
{
	
	if (e != NULL)
	{
		vector<Entidade*>::const_iterator iterador;
		iterador = lista.begin();
		Entidade* pEntidade = NULL;

		while (iterador != lista.end())
		{
			pEntidade = *iterador;
			if (pEntidade = e)
			{
				delete pEntidade;
				lista.erase(iterador);
				break;
			}
		}
	}
	else
		cout << "ERRO: Nao foi possivel remover a entidade da lista pois o ponteiro = NULL" << endl;
}

int ListaEntidades::getTamanho()
{
	return static_cast<int> (lista.size());
}

Entidade* ListaEntidades::operator[](int i)
{
	if (i >= 0 && i < lista.size())
		return lista[i];
	else
	{
		cout << "ERRO: Acesso indevido de memoria na lista" << endl;
		return NULL;
	}
}
