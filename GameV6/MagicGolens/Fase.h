#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "GerenciadorMapa.h"
#include "Fase.h"
#include "Mapa.h"
#include "GolemPedra.h"
#include "GolemFogo.h"
#include "GolemGelo.h"

class Fase
{
protected:
	ListaEntidades LEntidades;
	Jogador* jogador1;
	Jogador* jogador2;
	bool statusConcluida;
	const sf::Vector2f pontoFinal;

	Tile* pTile;
	Mapa* pMapa;
	GerenciadorMapa* pGm;
	sf::Texture backgroundText;
	sf::Sprite backgroundSpr;

public:

	//Construtora e Destrutora
	Fase(const char* caminhoTile = "", const char* caminhoMapa = "", const char* caminhoBackground = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f));
	~Fase();

	//Funcoes
	void setJogadores(Jogador* j1, Jogador* j2);
	void setConcluida(bool b);
	const bool getStatus() const;
	ListaEntidades* getListaEntidades();
	sf::Vector2f getPosicaoJogador() const;
	virtual void setPosicaoJogadores() = 0;
	virtual const sf::Vector2f getPontoFinal() const = 0;
	GerenciadorMapa* getGerenciadorMapa();
};

