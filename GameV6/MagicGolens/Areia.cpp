#include "stdafx.h"
#include "Areia.h"

Areia::Areia(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Obstaculo(ID, tam, p, v, caminhoTextura, t, j)
{
}

Areia::~Areia()
{
}

void Areia::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
}
