#pragma once
#include "Mapa.h"
#include "Tile.h"
#include "IdsColidiveis.h"
#include "Entidade.h"

class GerenciadorMapa
{
private:
	Mapa* pmapa;
	Tile* ptile;
	sf::Sprite* background;
	sf::RenderWindow* janela;
	vector<Tile*> listaTiles;

public:

	typedef struct dadosTiles {
		const IdsColidiveis Id;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	}DadosTiles;

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
	vector<DadosTiles> checarColisoes(IdsColidiveis IdEnt, sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt);
	bool estaoColidindo(IdsColidiveis IdEnt, sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt, sf::Vector2i tipoTile);
};
