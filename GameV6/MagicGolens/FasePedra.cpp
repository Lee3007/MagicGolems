#include "stdafx.h"
#include "FasePedra.h"

FasePedra::FasePedra(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j)
{
}

FasePedra::~FasePedra()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
		cout << "Jogador removido da fase pedra" << endl;
	}

	if (!LEntidades->getVaziaStatus())
		LEntidades->destruirEntidades();

	delete LEntidades;
	delete mapaTiles[0];
	delete mapaTiles[1];
	delete mapaTiles[2];
	delete mapaTiles[3];
}

void FasePedra::setPosicaoJogadores()
{
	jogador1->reiniciar();
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
	int qntd = rand() % 7 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2700 + 100);
		float py = static_cast<float>(rand() % 2700 + 100);

		GolemPedra* pGolemPedra = new GolemPedra(golemPedra, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(50.f, 0.f), "text/golemPedra.png", dt, janela);
		LEntidades->incluirEntidade(pGolemPedra);
		GColisoes->adicionarEntidade(pGolemPedra);
	}
}

void FasePedra::inicializarTiles(const char* caminhoTile)
{
	pTile = new Tile(caminhoTile, bloco);
	mapaTiles[0] = pTile;
	pTile = new Tile(caminhoTile, naocolidivel);
	mapaTiles[3] = pTile;
	pTile = new Tile(caminhoTile, areia);
	mapaTiles[1] = pTile;
	pTile = new Tile(caminhoTile, porta);
	mapaTiles[2] = pTile;
}