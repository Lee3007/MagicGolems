#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "Jogador.h"

class Jogo
{
private:

	//Gerenciadores
	GerenciadorGrafico GerenciadorGrafico;
	GerenciadorAtualizacoes GerenciadorAtualizacoes;
	sf::Clock* relogio;
	Jogador *jogador;
	ListaEntidades LEntidades;

public:

	//Construtora e Destrutora
	Jogo();
	~Jogo();

	//Funcoes
	void executarJogo();
};

