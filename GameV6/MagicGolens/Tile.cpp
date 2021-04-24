#include "stdafx.h"
#include "Tile.h"


Tile::Tile(const char* caminho) :
caminhoText(caminho)
{
	if (caminho == "")
		cout << "caminho vazio!!!!" << endl;

	if (!tileTexture.loadFromFile(caminho)) {
		cout << "Erro ao carregar a textura" << endl;
		exit(12345);
	}
	tileSprite.setTexture(tileTexture);

}

Tile::~Tile() {}

void Tile::setPosicao(int x, int y) {
	tileSprite.setPosition( (float)x, (float)y);
}

void Tile::setRectTextura(int x, int y) {
	tileSprite.setTextureRect(sf::IntRect(x, y, 16, 16));
	tileSprite.setScale(sf::Vector2f(6, 6) );
}

sf::Sprite Tile::getTileSprite() {
	return tileSprite;
}
