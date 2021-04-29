#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(tam, p, v, caminhoTextura, t, j)
{
}

void GolemGelo::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}
