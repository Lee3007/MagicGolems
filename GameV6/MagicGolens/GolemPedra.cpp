#include "stdafx.h"
#include "GolemPedra.h"

GolemPedra::GolemPedra(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
Personagem(tam, p, v, caminhoTextura)
{
}

GolemPedra::~GolemPedra()
{
}

void GolemPedra::atualizar(float t)
{
	posicao += velocidade * t;
	corpo.setPosition(posicao);
}

void GolemPedra::desenhar(sf::RenderWindow* j)
{
	j->draw(corpo);
}
