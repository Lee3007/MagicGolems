#include "stdafx.h"
#include "GerenciadorAtualizacoes.h"

GerenciadorAtualizacoes::GerenciadorAtualizacoes()
{
	LEntidades = NULL;
}

GerenciadorAtualizacoes::~GerenciadorAtualizacoes()
{
	LEntidades = NULL;
}

void GerenciadorAtualizacoes::setListaEntidades(ListaEntidades* L)
{
	if (L != NULL)
		LEntidades = L;
	else
		cout << "ERRO: Gerenciador de atualizacoes nao conseguiu receber a lista de forma correta" << endl;
}

void GerenciadorAtualizacoes::atualizar(float t)
{
	int i = 0;
	Entidade* pEntidade = NULL;

	for (i = 0; i < LEntidades->getTamanho(); i++)
	{
		pEntidade = LEntidades->operator[](i);
		pEntidade->atualizar(t);
	}
}
