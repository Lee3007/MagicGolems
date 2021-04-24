#pragma once
#include "Mapa.h"
#include "Tile.h"


class GerenciadorMapa
{
private:
	Mapa* pmapa;
	Tile* ptile;


public:
	GerenciadorMapa(Mapa* pm = NULL, Tile* pt = NULL);
	~GerenciadorMapa();

	//Métodos
	void setMapa(Mapa* pm);
	Mapa* getMapa() const;
	void setTile(Tile* pt);
	Tile* getTile() const;

	void desenhar(sf::RenderWindow* jan);


};
