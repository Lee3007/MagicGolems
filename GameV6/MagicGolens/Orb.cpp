#include "stdafx.h"
#include "Orb.h"

Orb::Orb(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Entidade(ID, tam, p, v, caminhoTextura, t, j)
{
}

Orb::~Orb()
{
}

void Orb::atualizar()
{
}

void Orb::desenhar()
{
}

void Orb::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{

}
