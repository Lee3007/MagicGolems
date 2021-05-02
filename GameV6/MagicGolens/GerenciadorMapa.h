#pragma once
#include "Mapa.h"
#include "Tile.h"
#include "IdsColidiveis.h"
#include "Entidade.h"
#include <map>

class GerenciadorMapa
{
private:
	Mapa* pmapa;
	sf::Sprite* background;
	sf::RenderWindow* janela;
	map <int, Tile*> mapaTiles;

public:

	typedef struct dadosTiles {
		const IdsColidiveis Id;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	}DadosTiles;

	GerenciadorMapa(map <int, Tile*> map = {}, Mapa* pm = NULL, sf::RenderWindow* j = NULL);
	~GerenciadorMapa();

	//M�todos
	void setMapa(Mapa* pm);
	Mapa* getMapa() const;
	void setBackground(sf::Sprite* sp );
	sf::Sprite* getBackground();
	void desenhar();
	sf::Vector2f converterCoordenadas(int i, int j);
	vector<DadosTiles> checarColisoes(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt);
	bool estaoColidindo(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt, sf::Vector2f posTile);
};
