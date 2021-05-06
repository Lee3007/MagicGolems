#include "stdafx.h"
#include "Porta.h"

Porta::Porta(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Tile(ID, tam, p, v, caminhoTextura, t, j)
{
}

Porta::~Porta()
{
}

void Porta::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
}
