#include "stdafx.h"
#include "GerenciadorMapa.h"

GerenciadorMapa::GerenciadorMapa(Mapa* pm, Tile* pt, sf::RenderWindow* j):
pmapa(pm),
ptile(pt)
{
	if ( pm == NULL || pt == NULL)
		system("pause");

	background = NULL;
	janela = j;
}

GerenciadorMapa::~GerenciadorMapa()
{

}



void GerenciadorMapa::desenhar()
{
	janela->draw(*background);
	for (int i = 0; i < 30; i++) 
	{
		for (int j = 0; j < 30; j++)
		{
			ptile->setPosicao(i * 96, j * 96);
			ptile->setRectTextura( (pmapa->getInfoXMapa(i, j)*16) , (pmapa->getInfoYMapa(i, j)*16) );
			janela->draw( ptile->getTileSprite() );

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

void GerenciadorMapa::setBackground(sf::Sprite* sp) {
	background = sp;
}

sf::Sprite* GerenciadorMapa::getBackground() {
	return background;
}