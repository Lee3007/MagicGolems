#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Id(ID),
	posicao(p),
	velocidade(v),
	textura(),
	sprite(),
	corpo(tam),
	dimensoes(tam),
	viradoDir(1),
	destruir(false)
{
	textura.loadFromFile(caminhoTextura);
	sprite.setTexture(textura);
	corpo.setTexture(sprite.getTexture());
	corpo.setOrigin(corpo.getSize() / 2.f);
	janela = j;
	dt = t;
	if (Id == jogador || Id == golemPedra || Id == golemFogo || Id == golemGelo)
	{
		dimensoes.x = dimensoes.x - 25.f;
		dimensoes.y = dimensoes.y - 15.f;
	}

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

bool Entidade::destruirEntidade() const
{
	return destruir;
}
