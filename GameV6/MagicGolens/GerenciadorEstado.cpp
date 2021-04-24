#include "stdafx.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"

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
	GAtualizacoes->setFase(fase1);
	GAtualizacoes->setListaEntidades(fase1->getListaEntidades());
	fase1->setPosicaoJogadores();
	bFase1 = true;
	bMenu = false;
}

void GerenciadorEstado::inicializarFase2()
{
	GGrafico->setListaEntidades(fase1->getListaEntidades());
	GAtualizacoes->setFase(fase1);
	GAtualizacoes->setListaEntidades(fase1->getListaEntidades());
	fase1->setPosicaoJogadores();
	//GGrafico->setListaEntidades(fase2->getListaEntidades());
	//GAtualizacoes->setListaEntidades(fase2->getListaEntidades());
	//GAtualizacoes->setFase(fase2);
	bFase2 = true;
	bMenu = false;
	bFase1 = false;
}

void GerenciadorEstado::inicializarFase3()
{
	//GGrafico->setListaEntidades(fase3->getListaEntidades());
	//GAtualizacoes->setListaEntidades(fase3->getListaEntidades());
	//GAtualizacoes->setFase(fase3);
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
			inicializarFase2();
			cout << "Inicializando fase 2!" << endl;
		}
	}
	else if (bFase2)
	{
		cout << "Fase2 sendo executada" << endl;
		/*if (fase2->getStatus())
		{
			bFase2 = false;
			inicializarFase3();
		}*/
	}
	else if (bFase3)
	{
		cout << "Fase3 sendo executada" << endl;
		/*fase3->getStatus();
		bFase3 = false;
		inicializarLeaderBoard();*/
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
