#include "stdafx.h"
#include "Tile.h"

Tile::Tile(const char* caminho, int i) :
caminhoText(caminho),
tipoTile(i)
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

void Tile::setPosicao(int x, int y) {
	tileSprite.setPosition((float)x, (float)y);
	tileCorpo.setPosition((float)x, (float)y);
}

void Tile::setRectTextura(int x, int y) {
	tileSprite.setTextureRect(sf::IntRect(x, y, 16, 16));
	tileSprite.setScale(sf::Vector2f(6, 6));
	tileCorpo.setSize(sf::Vector2f(96, 96));
	setTipoTile(x, y);

}

sf::Sprite Tile::getTileSprite() 
{
	return tileSprite;
}

sf::RectangleShape Tile::getTileRect() 
{
	return tileCorpo;
}

void Tile::setTipoTile(int x, int y) 
{
	if (x == 0 && y == 0)
		tipoTile = 0;
	else if (x == 1 && y == 0)
		tipoTile = 1;
	else if (x == 0 && y == 1)
		tipoTile = 2;
	else if (x == 1 && y == 1)
		tipoTile = 3;
	else if (x == 0 && y == 2)
		tipoTile = 4;

	if (y == 0) {
		if (x == 0)
			tipoTile = 0;
		else if (x == 1)
			tipoTile = 1;
	}
	else if (y == 1) {
		if (x == 0)
			tipoTile = 2;
		else if (x == 1)
			tipoTile = 3;
	}
	else if (y == 2) {
		if (x == 0)
			tipoTile = 4;
		else if (x == 1)
			tipoTile = 5;
	}
}

sf::Vector2f Tile::getPosicao()
{
	return tileCorpo.getPosition();
}
