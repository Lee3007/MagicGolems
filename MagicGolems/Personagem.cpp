#include "stdafx.h"
#include "Personagem.h"

//Construtora e Destrutora

Personagem::Personagem(sf::Vector2f p, sf::Vector2f v):
Entidade(p, v),
hp(100)
{
}

Personagem::~Personagem()
{
}
