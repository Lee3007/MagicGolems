#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
posicao(p),
velocidade(v),
textura(),
corpo(tam)
{
	textura.loadFromFile(caminhoTextura);
	corpo.setTexture(&textura);
}

Entidade::~Entidade()
{
}
