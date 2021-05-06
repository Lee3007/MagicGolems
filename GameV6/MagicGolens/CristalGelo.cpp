#include "stdafx.h"
#include "CristalGelo.h"

CristalGelo::CristalGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Arremessavel(ID, tam, p, v, caminhoTextura, t, j)
{
}

CristalGelo::~CristalGelo()
{
}

void CristalGelo::atualizar()
{
	velocidade.y += 9.81f / 2;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void CristalGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	if (IdOutro != naocolidivel && IdOutro != golemGelo && IdOutro != porta)
	{
		destruir = true;
	}

}