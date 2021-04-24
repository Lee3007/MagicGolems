#include "stdafx.h"
#include "MenuPause.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "MenuInicial.h"

MenuPause::MenuPause(GerenciadorEstado* Ge, GerenciadorGrafico* Gg):
Menu(Ge, Gg),

opcoes()
{
	MenuIni = NULL;
	inicializarMenu();
}

MenuPause::~MenuPause()
{
}

void MenuPause::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color::Cyan);
	opcoes[0].setString("Voltar ao jogo");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 3 * 1));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Menu principal");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 3 * 2));
}

void MenuPause::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color::Cyan);
	}
}

void MenuPause::moverBaixo()
{
	if (itemSelecionado + 1 <= 1)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color::Cyan);
	}
}

void MenuPause::desenhar(sf::RenderWindow* j)
{
	for (int i = 0; i < 2; i++)
	{
		j->draw(opcoes[i]);
	}
}

void MenuPause::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GEstado->setMenuStatus(false);
		break;

	case 1:
		GGrafico->setMenu(MenuIni);
		break;

	}
}

void MenuPause::setMenuInicial(MenuInicial* m)
{
	if (m != NULL)
		MenuIni = m;
	else
	{
		cout << "ERRO: MenuPause nao recebeu devidamente o menu inicial" << endl;
		exit(890);
	}
}