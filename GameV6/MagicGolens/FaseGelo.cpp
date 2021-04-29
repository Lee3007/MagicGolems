#include "stdafx.h"
#include "FaseGelo.h"

FaseGelo::FaseGelo(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j):
Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j)
{
}

FaseGelo::~FaseGelo()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
		cout << "Jogador removido da fase gelo" << endl;
	}

	if (!LEntidades->getVaziaStatus())
		LEntidades->destruirEntidades();

	delete LEntidades;
}

void FaseGelo::setPosicaoJogadores()
{
	jogador1->setPosicao(sf::Vector2f(3.5 * 96.f, 5 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(4.5 * 96.f, 5 * 96.f));
	}
}

const sf::Vector2f FaseGelo::getPontoFinal() const
{
	return pontoFinal;
}

void FaseGelo::criarInimigos()
{
	int qntd = rand() % 7 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 1000);
		float py = static_cast<float>(rand() % 500);

		GolemGelo* pGolemGelo = new GolemGelo(sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(2.f, -5.f), "text/golemGelo.png", dt, janela);
		LEntidades->incluirEntidade(pGolemGelo);
	}

	GolemGelo* pGolemGelo = new GolemGelo(sf::Vector2f(288.f, 432.f), sf::Vector2f(1920.f, 2060.f), sf::Vector2f(2.f, -5.f), "text/golemGelo.png", dt, janela);
	LEntidades->incluirEntidade(pGolemGelo);
}