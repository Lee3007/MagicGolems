#include "stdafx.h"
#include "FasePedra.h"

FasePedra::FasePedra(int i):
Fase(i)
{

}

FasePedra::~FasePedra()
{
}

void FasePedra::setPosicaoJogadores()
{
	jogador1->setPosicao(sf::Vector2f(400.f, 300.f));
	
	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(500.f, 300.f));
	}
}

const sf::Vector2f FasePedra::getPontoFinal() const
{
	return pontoFinal;
}
