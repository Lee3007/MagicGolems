#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
Personagem(tam, p, v, caminhoTextura)
{
}

void GolemGelo::atualizar(float t)
{
	posicao += velocidade * t;
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar(sf::RenderWindow* j)
{
	j->draw(corpo);
}
