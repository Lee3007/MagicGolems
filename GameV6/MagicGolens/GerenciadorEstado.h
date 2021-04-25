#pragma once
#include "stdafx.h"
#include "Fase.h"

class GerenciadorAtualizacoes;
class GerenciadorGrafico;
class Menu;

class GerenciadorEstado
{
private:
	Fase* fase1;
	Fase* fase2;
	Fase* fase3;
	Menu* menu;
	GerenciadorGrafico* GGrafico;
	GerenciadorAtualizacoes* GAtualizacoes;
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
	void setFases(Fase* f1, Fase* f2, Fase* f3);
	void setGerenciadores(GerenciadorGrafico* Gg, GerenciadorAtualizacoes* Ga);
	void verificaEstado();
	void setMenu(Menu* m);
	bool menuAtivo() const;
	void setMenuStatus(bool b);
};

