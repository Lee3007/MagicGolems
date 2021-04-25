#include "stdafx.h"
#include "FaseFogo.h"

FaseFogo::FaseFogo(const char* caminhoTile, const char* caminhoMapa, sf::Vector2f ponto):
Fase(caminhoTile, caminhoMapa, ponto)
{
	criarInimigos();
}

FaseFogo::~FaseFogo()
{
}

void FaseFogo::setPosicaoJogadores()
{
	jogador1->setPosicao(sf::Vector2f(4 * 96.f, 6 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(500.f, 300.f));
	}
}

const sf::Vector2f FaseFogo::getPontoFinal() const
{
	return pontoFinal;
}

void FaseFogo::criarInimigos()
{
	srand(time(NULL));

	int qntd = rand() % 7 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = rand() % 1000;
		float py = rand() % 500;

		GolemFogo* pGolemFogo = new GolemFogo(sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(2.f, -5.f), "text/golemFogo.png");
		LEntidades.incluirEntidade(pGolemFogo);
	}
}
