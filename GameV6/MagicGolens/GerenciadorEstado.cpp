#include "stdafx.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "Menu.h"

GerenciadorEstado::GerenciadorEstado() :
	bFase1(false),
	bFase2(false),
	bFase3(false),
	bMenu(true),
	coop(false)
{
	GGrafico = NULL;
	GAtualizacoes = NULL;
	GColisoes = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
	menu = NULL;
	jogador1 = NULL;
	jogador2 = NULL;
}

GerenciadorEstado::~GerenciadorEstado()
{
	GGrafico = NULL;
	GAtualizacoes = NULL;
	GColisoes = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
	menu = NULL;
	jogador1 = NULL;
	jogador2 = NULL;
}

void GerenciadorEstado::inicializarFase1()
{
	if (coop)
		fase1->inicializarFase(jogador1, jogador2);
	else
	{
		cout << "1 player" << endl;
		fase1->inicializarFase(jogador1, NULL);
	}

	GGrafico->setListaEntidades(fase1->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase1->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase1->getGerenciadorMapa());
	GAtualizacoes->setFase(fase1);
	GAtualizacoes->setListaEntidades(fase1->getListaEntidades());
	bMenu = false;
	bFase1 = true;
	bFase2 = false;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase2()
{
	if (coop)
		fase2->inicializarFase(jogador1, jogador2);
	else
		fase2->inicializarFase(jogador1, NULL);

	GGrafico->setListaEntidades(fase2->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase2->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase2->getGerenciadorMapa());
	GAtualizacoes->setFase(fase2);
	GAtualizacoes->setListaEntidades(fase2->getListaEntidades());
	bMenu = false;
	bFase1 = false;
	bFase2 = true;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase3()
{
	if (coop)
		fase3->inicializarFase(jogador1, jogador2);
	else
		fase3->inicializarFase(jogador1, NULL);

	GGrafico->setListaEntidades(fase3->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase3->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase3->getGerenciadorMapa());
	GAtualizacoes->setListaEntidades(fase3->getListaEntidades());
	GAtualizacoes->setFase(fase3);
	bMenu = false;
	bFase1 = false;
	bFase2 = false;
	bFase3 = true;
}

void GerenciadorEstado::reiniciarFases()
{
	fase1->reiniciarFase();
	fase2->reiniciarFase();
	fase3->reiniciarFase();
}

void GerenciadorEstado::esvaziarGColisoes()
{
	GColisoes->esvaziar();
}

void GerenciadorEstado::setFases(Fase* f1, Fase* f2, Fase* f3)
{
	fase1 = f1;
	fase2 = f2;
	fase3 = f3;
}

void GerenciadorEstado::setGerenciadores(GerenciadorGrafico* Gg, GerenciadorAtualizacoes* Ga, GerenciadorColisoes* Gc)
{
	if (Gg != NULL && Ga != NULL && Gc != NULL)
	{
		GGrafico = Gg;
		GAtualizacoes = Ga;
		GColisoes = Gc;
	}
	else
	{
		cout << "ERRO: Gerenciador de estados nao conseguiu receber os gerenciadores de forma correta" << endl;
		exit(432);
	}
}

void GerenciadorEstado::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;
}

void GerenciadorEstado::verificaEstado()
{
	if (bMenu)
	{
		//cout << "Menu ativo" << endl;
	}
	else if (bFase1)
	{
		//cout << "Fase1 sendo executada" << endl;
		if (fase1->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			GColisoes->esvaziar();
			inicializarFase2();
			cout << "Inicializando fase 2!" << endl;
		}
	}
	else if (bFase2)
	{
		//cout << "Fase2 sendo executada" << endl;
		if (fase2->getStatus())
		{
			bFase2 = false;
			bFase1 = false;
			bMenu = false;
			GColisoes->esvaziar();
			inicializarFase3();
			cout << "Inicializando fase 3!" << endl;
		}
	}
	else if (bFase3)
	{
		//cout << "Fase3 sendo executada" << endl;
		if (fase3->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			bMenu = true;
			GColisoes->esvaziar();
			//fase1->setConcluida(false);
			//fase2->setConcluida(false);
			//fase3->setConcluida(false);
			reiniciarFases();
			GGrafico->setMenu(menu);
			//*inicializarLeaderBoard();
		}
	}
}

void GerenciadorEstado::setMenu(Menu* m)
{
	if (m != NULL)
	{
		menu = m;
	}
	else
	{
		cout << "ERRO: GerenciadorEstado nao recebeu menu corretamente" << endl;
	}
}

bool GerenciadorEstado::menuAtivo() const
{
	return bMenu;
}

void GerenciadorEstado::setMenuStatus(bool b)
{
	bMenu = b;
}

void GerenciadorEstado::setCoop(bool b)
{
	coop = b;
}
