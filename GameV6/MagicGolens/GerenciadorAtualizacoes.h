#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Fase.h"
#include "Menu.h"
#include "GerenciadorGrafico.h"

class GerenciadorEstado;

class GerenciadorAtualizacoes
{
private:
	GerenciadorEstado* GEstado;
	ListaEntidades* LEntidades;
	Fase* fase;
	sf::Clock relogio;
	float dt;

public:
	GerenciadorAtualizacoes();
	~GerenciadorAtualizacoes();
	void setGerenciador(GerenciadorEstado* Ge);
	void setListaEntidades(ListaEntidades* L);
	void relogioRestart();
	void atualizar();
	void setFase(Fase* f);
	sf::Vector2f* getPosicaoJogador();
	float calcularDistancia(sf::Vector2f pj, sf::Vector2f pf);
};

