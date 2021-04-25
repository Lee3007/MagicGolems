#include "stdafx.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "Menu.h"

GerenciadorEstado::GerenciadorEstado():
bFase1(false),
bFase2(false),
bFase3(false),
bMenu(true)
{
	GGrafico = NULL;
	GAtualizacoes = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
	menu = NULL;
}

GerenciadorEstado::~GerenciadorEstado()
{

}

void GerenciadorEstado::inicializarFase1()
{
	if (fase1 == NULL)
	{
		cout << "Fase1 = NULL no inicializarFase1" << endl;
	}

	GGrafico->setListaEntidades(fase1->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase1->getGerenciadorMapa());
	GAtualizacoes->setFase(fase1);
	GAtualizacoes->setListaEntidades(fase1->getListaEntidades());
	fase1->setPosicaoJogadores();
	bMenu = false;
	bFase1 = true;
	bFase2 = false;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase2()
{
	GGrafico->setListaEntidades(fase2->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase2->getGerenciadorMapa());
	GAtualizacoes->setFase(fase2);
	GAtualizacoes->setListaEntidades(fase2->getListaEntidades());
	fase2->setPosicaoJogadores();
	bMenu = false;
	bFase1 = false;
	bFase2 = true;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase3()
{
	GGrafico->setListaEntidades(fase3->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase3->getGerenciadorMapa());
	GAtualizacoes->setListaEntidades(fase3->getListaEntidades());
	GAtualizacoes->setFase(fase3);
	fase3->setPosicaoJogadores();
	bMenu = false;
	bFase1 = false;
	bFase2 = false;
	bFase3 = true;
}

void GerenciadorEstado::setFases(Fase* f1, Fase* f2, Fase* f3)
{
	fase1 = f1;
	fase2 = f2;
	fase3 = f3;
}

void GerenciadorEstado::setGerenciadores(GerenciadorGrafico* Gg, GerenciadorAtualizacoes* Ga)
{
	if (Gg != NULL && Ga != NULL)
	{
		GGrafico = Gg;
		GAtualizacoes = Ga;
	}
	else
	{
		cout << "ERRO: Gerenciador de estados nao conseguiu receber os gerenciadores de forma correta" << endl;
		exit(432);
	}
}

void GerenciadorEstado::verificaEstado()
{
	if (bMenu)
	{
		cout << "Menu ativo" << endl;
	}
	else if (bFase1)
	{
		cout << "Fase1 sendo executada" << endl;
		if (fase1->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			inicializarFase2();
			cout << "Inicializando fase 2!" << endl;
		}
	}
	else if (bFase2)
	{
		cout << "Fase2 sendo executada" << endl;
		if (fase2->getStatus())
		{
			bFase2 = false;
			bFase1 = false;
			bMenu = false;
			inicializarFase3();
			cout << "Inicializando fase 3!" << endl;
		}
	}
	else if (bFase3)
	{
		cout << "Fase3 sendo executada" << endl;
		if (fase3->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			bMenu = true;
			fase1->setConcluida(false);
			fase2->setConcluida(false);
			fase3->setConcluida(false);
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
