#pragma once
#include "IdsColidiveis.h"

class Tile
{
private:
	const IdsColidiveis Id;
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	const char* caminhoText;

public:
	Tile(const char* caminho = "", const IdsColidiveis i = standby);
	~Tile();

	void setPosicao(int x, int y);
	void setRectTextura(int x, int y);
	sf::Vector2f getDimensoes() const;
	sf::Sprite getTileSprite();
	IdsColidiveis getId() const;
};
