#include "stdafx.h"
#include "GolemFogo.h"

GolemFogo::GolemFogo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
Personagem(tam, p, v, caminhoTextura)
{
}

GolemFogo::~GolemFogo()
{
}

void GolemFogo::atualizar(float t)
{
	posicao += velocidade * t;
	corpo.setPosition(posicao);
}

void GolemFogo::desenhar(sf::RenderWindow* j)
{
	j->draw(corpo);
}
