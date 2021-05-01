#include "stdafx.h"
#include "GerenciadorMapa.h"

GerenciadorMapa::GerenciadorMapa(Mapa* pm, Tile* pt, sf::RenderWindow* j):
pmapa(pm),
ptile(pt),
listaTiles()
{
	if (pm == NULL || pt == NULL)
		exit(80);

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

vector<GerenciadorMapa::DadosTiles> GerenciadorMapa::checarColisoes(IdsColidiveis IdEnt, sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt)
{
	vector<DadosTiles> colisoes;

	return colisoes;
}


bool GerenciadorMapa::estaoColidindo(IdsColidiveis IdEnt, sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt, sf::Vector2i tipoTile)
{
	if(tipoTile == sf::Vector2i(1,2))
		return false;

	return true;
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