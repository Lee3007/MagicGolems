#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include <fstream>

class GerenciadorAtualizacoes;
class GerenciadorGrafico;
class Menu;

class GerenciadorEstado
{
private:
	Jogador* jogador1;
	Jogador* jogador2;
	Fase* fase1;
	Fase* fase2;
	Fase* fase3;
	Menu* menu;
	GerenciadorGrafico* GGrafico;
	GerenciadorAtualizacoes* GAtualizacoes;
	GerenciadorColisoes* GColisoes;
	bool coop;
	bool bFase1;
	bool bFase2;
	bool bFase3;
	bool bMenu;

public:

	GerenciadorEstado();
	~GerenciadorEstado();
	void inicializarFase1();
	void inicializarFase2();
	void inicializarFase3();
	void reiniciarFases();
	void esvaziarGColisoes();
	void setFases(Fase* f1, Fase* f2, Fase* f3);
	void setGerenciadores(GerenciadorGrafico* Gg, GerenciadorAtualizacoes* Ga, GerenciadorColisoes* Gc);
	void setJogadores(Jogador* j1, Jogador* j2 = NULL);
	void verificaEstado();
	void setMenu(Menu* m);
	bool menuAtivo() const;
	void setMenuStatus(bool b);
	void setCoop(bool b);

	//new
	void salvarJogada();

	void inicializaFaseSalvada();
};
