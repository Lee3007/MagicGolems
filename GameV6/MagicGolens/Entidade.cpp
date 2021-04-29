#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
posicao(p),
velocidade(v),
textura(),
corpo(tam)
{
	textura.loadFromFile(caminhoTextura);
	corpo.setTexture(&textura);
	corpo.setOrigin(corpo.getSize() / 2.f);
	janela = j;
	dt = t;
}

Entidade::~Entidade()
{

}

void Entidade::setPosicao(sf::Vector2f p)
{
	posicao = p;
	corpo.setPosition(posicao);
}

sf::Vector2f Entidade::getPosicao()
{
	return corpo.getPosition();
}