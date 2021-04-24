#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "GerenciadorEstado.h"
#include "Jogador.h"
#include "FasePedra.h"
#include "MenuInicial.h"

class Jogo
{
private:

	//Gerenciadores
	GerenciadorGrafico GerenciadorGrafico;
	GerenciadorAtualizacoes GerenciadorAtualizacoes;
	GerenciadorEstado GerenciadorEstado;

	MenuInicial menu;

	//Entidades
	Jogador *jogador1;

	//Fases
	FasePedra fasePedra;

public:

	//Construtora e Destrutora
	Jogo();
	~Jogo();

	//Funcoes
	void executarJogo();
	void inicializarGerenciadores();

};

