#include "stdafx.h"
#include "FasePedra.h"

FasePedra::FasePedra(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto) :
Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto)
{
}

FasePedra::~FasePedra()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
		cout << "Jogador removido da fase pedra" << endl;
	}

	if(!LEntidades->getVaziaStatus())
		LEntidades->destruirEntidades();

	delete LEntidades;
}

void FasePedra::setPosicaoJogadores()
{
	jogador1->setPosicao(sf::Vector2f(3.5 * 96.f, 28 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(4.5 * 96.f, 28 * 96.f));
	}
}

const sf::Vector2f FasePedra::getPontoFinal() const
{
	return pontoFinal;
}

void FasePedra::criarInimigos()
{
	srand(time(NULL));

	int qntd = rand() % 7 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = rand() % 1000;
		float py = rand() % 500;

		GolemPedra* pGolemPedra = new GolemPedra(sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(2.f, -5.f), "text/golemPedra.png");
		LEntidades->incluirEntidade(pGolemPedra);
	}
}
