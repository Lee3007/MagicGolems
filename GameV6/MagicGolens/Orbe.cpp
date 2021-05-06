#include "stdafx.h"
#include "Orbe.h"

Orbe::Orbe(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Arremessavel(ID, tam, p, v, caminhoTextura, t, j)
{
}

Orbe::~Orbe()
{
}

void Orbe::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void Orbe::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	if (IdOutro != naocolidivel && IdOutro != jogador && IdOutro != porta)
	{
		destruir = true;
	}

}