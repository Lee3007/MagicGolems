#include "stdafx.h"
#include "FasePedra.h"

FasePedra::FasePedra(const char* caminhoTile, const char* caminhoMapa) :
Fase(caminhoTile, caminhoMapa)
{

}

FasePedra::~FasePedra()
{
}

void FasePedra::setPosicaoJogadores()
{
	jogador1->setPosicao(sf::Vector2f(4 * 96.f, 6 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(500.f, 300.f));
	}
}

const sf::Vector2f FasePedra::getPontoFinal() const
{
	return pontoFinal;
}
