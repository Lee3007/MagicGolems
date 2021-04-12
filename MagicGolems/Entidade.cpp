#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(sf::Vector2f p, sf::Vector2f v):
posicao(p),
velocidade(v),
corpo(sf::Vector2f(80.f,120.f))
{
	textura = NULL;
}

Entidade::~Entidade()
{
}
