#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Id(ID),
	posicao(p),
	velocidade(v),
	textura(),
	corpo(tam),
	dimensoes(tam)
{
	textura.loadFromFile(caminhoTextura);
	corpo.setTexture(&textura);
	corpo.setOrigin(corpo.getSize() / 2.f);
	janela = j;
	dt = t;
	dimensoes.x = dimensoes.x - 15.f;
	dimensoes.y = dimensoes.y - 15.f;
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
	return posicao;
}

sf::Vector2f Entidade::getDimensoes()
{
	return dimensoes;
}

const IdsColidiveis Entidade::getId()
{
	return Id;
}