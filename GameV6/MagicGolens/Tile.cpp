#include "stdafx.h"
#include "Tile.h"

Tile::Tile(const char* caminho, const IdsColidiveis i) :
caminhoText(caminho),
Id(i)
{
	if (caminho == "")
		cout << "caminho vazio!!!!" << endl;
	else {
		if (!tileTexture.loadFromFile(caminho)) {
			cout << "Erro ao carregar a textura" << endl;
			exit(12345);
		}

		tileSprite.setTexture(tileTexture);
	}
}

Tile::~Tile() {}

void Tile::setPosicao(float x, float y) {


	tileSprite.setPosition(x, y);
}

void Tile::setRectTextura(int x, int y) {
	tileSprite.setTextureRect(sf::IntRect(x, y, 16, 16));
	tileSprite.setScale(sf::Vector2f(6, 6));
}

sf::Vector2f Tile::getDimensoes() const
{
	return sf::Vector2f(96.f, 96.f);
}

sf::Sprite Tile::getTileSprite() 
{
	return tileSprite;
}

IdsColidiveis Tile::getId() const
{
	return Id;
}
