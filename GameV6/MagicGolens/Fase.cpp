#include "stdafx.h"
#include "Fase.h"

Fase::Fase(const char* caminhoTile, const char* caminhoMapa) :
	LEntidades(),
	statusConcluida(false),
	pontoFinal(sf::Vector2f(0.f, 0.f))
{
	jogador1 = NULL;
	jogador2 = NULL;
	pTile = new Tile(caminhoTile);
	pMapa = new Mapa(caminhoMapa);
	pGm = new GerenciadorMapa(pMapa, pTile);				//.......................

}

Fase::~Fase()
{
	delete (pTile);
	pTile = NULL;
	delete (pMapa);
	pMapa = NULL;
	delete (pGm);
	pGm = NULL;

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

GerenciadorMapa* Fase::getGerenciadorMapa() {
	return pGm;
}