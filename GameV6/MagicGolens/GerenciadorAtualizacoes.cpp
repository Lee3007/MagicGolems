#include "stdafx.h"
#include "GerenciadorAtualizacoes.h"
#include "GerenciadorEstado.h"

GerenciadorAtualizacoes::GerenciadorAtualizacoes():
relogio(),
dt(0.f)
{
	GEstado = NULL;
	LEntidades = NULL;
	fase = NULL;
	relogio.restart();
}

GerenciadorAtualizacoes::~GerenciadorAtualizacoes()
{
	LEntidades = NULL;
}

void GerenciadorAtualizacoes::setGerenciador(GerenciadorEstado* Ge)
{
	if (Ge != NULL)
	{
		GEstado = Ge;
	}
	else
	{
		cout << "ERRO: Gerenciador de atualizacoes nao conseguir receber o gerenciador de estados corretamente" << endl;
		exit(987);
	}
}

void GerenciadorAtualizacoes::setListaEntidades(ListaEntidades* L)
{
	if (L != NULL)
		LEntidades = L;
	else
		cout << "ERRO: Gerenciador de atualizacoes nao conseguiu receber a lista de forma correta" << endl;
}

void GerenciadorAtualizacoes::relogioRestart()
{
	dt = relogio.restart().asSeconds();
}

void GerenciadorAtualizacoes::atualizar()
{
	if (!GEstado->menuAtivo())
	{
		Entidade* pEntidade = NULL;
		sf::Vector2f p;

		for (int i = 0; i < LEntidades->getTamanho(); i++)
		{
			pEntidade = LEntidades->operator[](i);
			pEntidade->atualizar(dt);
		}

		p = fase->getPosicaoJogador();

		if (p.x >= 0 && p.x <= 60 && p.y >= 0 && p.y <= 60)
		{
			fase->setConcluida();
		}
	}
}

void GerenciadorAtualizacoes::setFase(Fase* f)
{
	if (f != NULL)
		fase = f;
	else
	{
		cout << "ERRO: Gerenciador de atualizacoes nao conseguiu receber a fase devidamente" << endl;
		exit(244);
	}
}
