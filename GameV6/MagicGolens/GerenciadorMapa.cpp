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

vector<GerenciadorMapa::DadosTiles> GerenciadorMapa::checarColisoes(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt)
{
	vector<GerenciadorMapa::DadosTiles> colisoes;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			sf::Vector2i coordTile;
			coordTile.x = i;
			coordTile.y = j;

			sf::Vector2i tipoTile = pmapa->getInfoMapa(i, j);
			if (tipoTile == sf::Vector2i(0, 0) || (tipoTile == sf::Vector2i(0, 1)))
			{
				sf::Vector2f t;
				t.x = 96.f;
				t.y = 96.f;

				sf::Vector2f p;
				p.x = (96.f * coordTile.x) + (96 / 2.f);
				p.y = (96.f * coordTile.y) + (96 / 2.f);

				if (estaoColidindo(posicaoEnt, tamanhoEnt, p))
				{
					if (tipoTile == sf::Vector2i(0, 0))
						colisoes.push_back({ chao, p, t });
					else if (tipoTile == sf::Vector2i(0, 1))
						colisoes.push_back({ areia, p, t });
				}
			}
		}
	}

	return colisoes;
}

bool GerenciadorMapa::estaoColidindo(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt, sf::Vector2f posTile)
{
	sf::Vector2f dist = posicaoEnt - posTile;

	if ((fabsf(dist.x) < ((tamanhoEnt.x + 96) / 2)) && (fabsf(dist.y) < ((tamanhoEnt.y + 96) / 2)))
		return true;

	return false;
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