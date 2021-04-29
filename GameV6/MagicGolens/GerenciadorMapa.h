#pragma once
#include "Mapa.h"
#include "Tile.h"


class GerenciadorMapa
{
private:
	Mapa* pmapa;
	Tile* ptile;
	sf::Sprite* background;
	sf::RenderWindow* janela;

public:
	GerenciadorMapa(Mapa* pm = NULL, Tile* pt = NULL, sf::RenderWindow* j = NULL);
	~GerenciadorMapa();

	//Métodos
	void setMapa(Mapa* pm);
	Mapa* getMapa() const;
	void setTile(Tile* pt);
	Tile* getTile() const;
	void setBackground(sf::Sprite* sp );
	sf::Sprite* getBackground();
	void desenhar();


};
