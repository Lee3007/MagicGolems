#include "stdafx.h"
#include "Fase.h"

Fase::Fase(int i):
LEntidades(),
statusConcluida(false),
pontoFinal(sf::Vector2f(0.f, 0.f))
{
	jogador1 = NULL;
	jogador2 = NULL;
}

Fase::~Fase()
{
}

void Fase::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;

	if (j1 != NULL)
	{
		float x;
		float y;

		sf::Vector2f p = getPosicaoJogador();

		x = p.x;
		y = p.y;

		cout << "Jogador recebido pela fase com sucesso" << endl;
		cout << "xo = " << x << endl << "yo = " << y << endl;
	}

	LEntidades.incluirEntidade(j1);

	if (j2 != NULL)
	{
		LEntidades.incluirEntidade(j2);
	}
		
}

void Fase::setConcluida()
{
	statusConcluida = true;
}

const bool Fase::getStatus() const
{
	return statusConcluida;
}

ListaEntidades* Fase::getListaEntidades()
{
	return &LEntidades;
}

sf::Vector2f Fase::getPosicaoJogador() const
{
	return jogador1->getPosicao();
}

const sf::Vector2f Fase::getPontoFinal() const
{
	return pontoFinal;
}
