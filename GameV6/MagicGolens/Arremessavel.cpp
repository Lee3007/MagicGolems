#include "stdafx.h"
#include "Arremessavel.h"

Arremessavel::Arremessavel(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, Entidade* eAt) :
	Entidade(ID, tam, p, v, caminhoTextura, t, j),
	velDir(sf::Vector2f(0.f, 0.f)),
	enteAtirador(eAt)
{
}

Arremessavel::~Arremessavel()
{
}

void Arremessavel::desenhar()
{
	janela->draw(corpo);
}

void Arremessavel::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
}