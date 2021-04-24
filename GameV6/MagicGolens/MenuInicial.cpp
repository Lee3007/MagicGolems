#include "stdafx.h"
#include "MenuInicial.h"

MenuInicial::MenuInicial(GerenciadorEstado* Ge, GerenciadorGrafico* Gg):
Menu(Ge, Gg),
opcoes(),
MFases(Ge, Gg),
MPause(Ge, Gg)
{
	inicializarMenu();
	MFases.setMenuInicial(this);
	MPause.setMenuInicial(this);
}

MenuInicial::~MenuInicial()
{
}

void MenuInicial::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color::Cyan);
	opcoes[0].setString("Jogar");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 4 * 1));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Leaderboard");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 4 * 2));

	opcoes[2].setFont(fonte);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setString("Sair");
	opcoes[2].setOrigin(opcoes[2].getLocalBounds().width / 2, opcoes[2].getLocalBounds().height / 2);
	opcoes[2].setPosition(sf::Vector2f(1280 / 2.f, 720 / 4 * 3));
}

void MenuInicial::desenhar(sf::RenderWindow* j)
{
	for (int i = 0; i < 3; i++)
	{
		j->draw(opcoes[i]);
	}
}

void MenuInicial::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color::Cyan);
	}
}

void MenuInicial::moverBaixo()
{
	if (itemSelecionado + 1 <= 2)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color::Cyan);
	}
}

void MenuInicial::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GGrafico->setMenu(&MFases);
		break;

	case 1:
		break;

	case 2:
		GGrafico->fecharJanela();
		break;
	}
}

MenuPause* MenuInicial::getMenuPause()
{
	return &MPause;
}
