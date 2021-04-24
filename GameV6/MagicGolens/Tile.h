#pragma once
class Tile
{
private:
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	const char* caminhoText;

public:
	Tile(const char* caminho = "");
	~Tile();

	void setPosicao(int x, int y);
	void setRectTextura(int x, int y);
	sf::Sprite getTileSprite();

};

