#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "GerenciadorMapa.h"
#include "GerenciadorColisoes.h"
#include "Mapa.h"
#include "GolemPedra.h"
#include "GolemFogo.h"
#include "GolemGelo.h"
#include "Tile.h"
#include <map>
using namespace std;

class Fase
{
protected:
	ListaEntidades* LEntidades;
	Jogador* jogador1;
	Jogador* jogador2;
	bool statusConcluida;
	const sf::Vector2f pontoFinal;
	float* dt;
	sf::RenderWindow* janela;
	Tile* pTile;
	Mapa* pMapa;
	GerenciadorMapa* pGm;
	GerenciadorColisoes* GColisoes;
	sf::Texture backgroundText;
	sf::Sprite backgroundSpr;
	map<int, Tile*> mapaTiles;
	const char* caminhoTile;
	const char* caminhoMapa;
	const char* caminhoBackground;

public:

	//Construtora e Destrutora
	Fase(const char* caminhoTile = "", const char* caminhoMapa = "", const char* caminhoBackground = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f), float* t = NULL, sf::RenderWindow* j = NULL);
	~Fase();

	//Funcoes
	void inicializarFase(Jogador* j1, Jogador* j2);
	void reiniciarFase();
	virtual void inicializarTiles(const char* caminhoTile) = 0;
	void criarMapa();
	void setJogadores(Jogador* j1, Jogador* j2);
	virtual void criarInimigos() = 0;
	void setConcluida(bool b);
	const bool getStatus() const;
	ListaEntidades* getListaEntidades();
	sf::Vector2f getPosicaoJogador() const;
	virtual void setPosicaoJogadores() = 0;
	virtual const sf::Vector2f getPontoFinal() const = 0;
	GerenciadorMapa* getGerenciadorMapa();
	void setGerenciadorColisoes(GerenciadorColisoes* pg);
	bool jogadorMorto();
};