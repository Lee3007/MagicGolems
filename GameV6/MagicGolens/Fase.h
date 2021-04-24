#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "GerenciadorMapa.h"
#include "Fase.h"
#include "Mapa.h"

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

public:

	//Construtora e Destrutora
	Fase(int i = -1, const char* caminhoTile = "", const char* caminhoMapa = "");
	~Fase();

	//Funcoes
	void setJogadores(Jogador* j1, Jogador* j2);
	void setConcluida();
	const bool getStatus() const;
	ListaEntidades* getListaEntidades();
	sf::Vector2f getPosicaoJogador() const;
	virtual void setPosicaoJogadores() = 0;
	virtual const sf::Vector2f getPontoFinal() const = 0;
	GerenciadorMapa* getGerenciadorMapa();

};

