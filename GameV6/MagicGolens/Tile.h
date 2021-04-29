#pragma once
class Tile
{
private:
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	const char* caminhoText;
	sf::RectangleShape tileCorpo;
	int tipoTile;

public:
	Tile(const char* caminho = "", int i = -1);
	~Tile();

	void setPosicao(int x, int y);
	void setRectTextura(int x, int y);
	sf::Sprite getTileSprite();
	sf::RectangleShape getTileRect();
	void setTipoTile(int x, int y);
	sf::Vector2f getPosicao();
};
