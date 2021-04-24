#include "stdafx.h"
#include "Personagem.h"

//Construtora e Destrutora

Personagem::Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
Entidade(tam, p, v, caminhoTextura),
hp(100)
{
}

Personagem::~Personagem()
{
}
