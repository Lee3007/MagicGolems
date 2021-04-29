#include "stdafx.h"
#include "GolemFogo.h"

GolemFogo::GolemFogo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(tam, p, v, caminhoTextura, t, j)
{
}

GolemFogo::~GolemFogo()
{
}

void GolemFogo::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemFogo::desenhar()
{
	janela->draw(corpo);
}
