#include "stdafx.h"
#include "GerenciadorMapa.h"

GerenciadorMapa::GerenciadorMapa(Mapa* pm, Tile* pt):
pmapa(pm),
ptile(pt)
{
	if ( pm == NULL || pt == NULL)
		system("pause");
}

GerenciadorMapa::~GerenciadorMapa()
{

}



void GerenciadorMapa::desenhar(sf::RenderWindow* jan)
{
	for (int i = 0; i < 30; i++) 
	{
		for (int j = 0; j < 30; j++)
		{
			ptile->setPosicao(i * 96, j * 96);
			ptile->setRectTextura( (pmapa->getInfoXMapa(i, j)*16) , (pmapa->getInfoYMapa(i, j)*16) );
			jan->draw( ptile->getTileSprite() );

		}

	}

}

void GerenciadorMapa::setMapa(Mapa* pm)
{
	pmapa = pm;
}

Mapa* GerenciadorMapa::getMapa() const
{
	return pmapa;
}

void GerenciadorMapa::setTile(Tile* pt)
{
	ptile = pt;
}

Tile* GerenciadorMapa::getTile() const
{
	return ptile;
}