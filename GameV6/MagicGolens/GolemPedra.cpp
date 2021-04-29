#include "stdafx.h"
#include "GolemPedra.h"

GolemPedra::GolemPedra(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(tam, p, v, caminhoTextura, t, j)
{
}

GolemPedra::~GolemPedra()
{
}

void GolemPedra::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemPedra::desenhar()
{
	janela->draw(corpo);
}
