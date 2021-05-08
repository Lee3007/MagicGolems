#pragma once
#include "Entidade.h"

class Tile:
	public Entidade
{
protected:

public:
	Tile(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 96.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Tile();

	void setPosicao(float x, float y);
	void setRectTextura(int x, int y);
	sf::Sprite getTileSprite();
	void desenhar();
	virtual void atualizar();
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL) = 0;
	void salvar() {};
	void carregar() {};
};
