#include "stdafx.h"
#include "FaseFogo.h"

FaseFogo::FaseFogo(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j)
{
}

FaseFogo::~FaseFogo()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
		cout << "Jogador removido da fase fogo" << endl;
	}

	if (!LEntidades->getVaziaStatus())
	{
		LEntidades->destruirEntidades();
	}

	delete LEntidades;
	delete mapaTiles[0];
	delete mapaTiles[1];
	delete mapaTiles[2];
	delete mapaTiles[3];
}

void FaseFogo::setPosicaoJogadores()
{
	jogador1->reiniciar();
	jogador1->setPosicao(sf::Vector2f(27.5 * 96.f, 16 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->setPosicao(sf::Vector2f(28.5 * 96.f, 16 * 96.f));
	}
}

const sf::Vector2f FaseFogo::getPontoFinal() const
{
	return pontoFinal;
}

void FaseFogo::criarInimigos()
{
	int qntd = rand() % 16 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2700 + 100);
		float py = static_cast<float>(rand() % 2700 + 100);

		GolemFogo* pGolemFogo = new GolemFogo(golemFogo, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(120.f, 0.f), "text/golemFogo.png", dt, janela);
		LEntidades->incluirEntidade(pGolemFogo);
		GColisoes->adicionarEntidade(pGolemFogo);
	}
}

void FaseFogo::inicializarTiles(const char* caminhoTile)
{
	pTile = new Tile(caminhoTile, bloco);
	mapaTiles[0] = pTile;
	pTile = new Tile(caminhoTile, naocolidivel);
	mapaTiles[3] = pTile;
	pTile = new Tile(caminhoTile, fogo);
	mapaTiles[1] = pTile;
	pTile = new Tile(caminhoTile, porta);
	mapaTiles[2] = pTile;
}