#include "stdafx.h"
#include "FaseGelo.h"

FaseGelo::FaseGelo(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j)
{
}

FaseGelo::~FaseGelo()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
		cout << "Jogador1 removido da fase gelo" << endl;
	}

	if (jogador2 != NULL)
	{
		LEntidades->removerEntidade(jogador2);
		cout << "Jogador2 removido da fase gelo" << endl;
	}

	if (!LEntidades->getVaziaStatus())
		LEntidades->destruirEntidades();

	delete LEntidades;
	delete mapaTiles[0];
	delete mapaTiles[1];
	delete mapaTiles[2];
	delete mapaTiles[3];
}

void FaseGelo::setPosicaoJogadores()
{
	jogador1->reiniciar();
	jogador1->setPosicao(sf::Vector2f(3.5 * 96.f, 5 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->reiniciar();
		jogador2->setPosicao(sf::Vector2f(3.5 * 96.f, 5 * 96.f));
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
		float px = static_cast<float>(rand() % 2700 + 100);
		float py = static_cast<float>(rand() % 2700 + 100);

		GolemGelo* pGolemGelo = new GolemGelo(golemGelo, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(80.f, 80.f), "text/golemGelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pGolemGelo);
		GColisoes->adicionarEntidade(pGolemGelo);
		pGolemGelo->setListaEntidades(LEntidades);
		pGolemGelo->setGerenciadorColisoes(GColisoes);
	}

	GolemGelo* pGolemGelo = new GolemGelo(golemGelo, sf::Vector2f(288.f, 432.f), sf::Vector2f(1920.f, 2060.f), sf::Vector2f(0.f, 0.f), "text/golemGelo.png", dt, janela, jogador1, jogador2);
	LEntidades->incluirEntidade(pGolemGelo);
	GColisoes->adicionarEntidade(pGolemGelo);
	pGolemGelo->setListaEntidades(LEntidades);
	pGolemGelo->setGerenciadorColisoes(GColisoes);
}

void FaseGelo::inicializarTiles(const char* caminhoTile)
{
	pTile = new Tile(caminhoTile, bloco);
	mapaTiles[0] = pTile;
	pTile = new Tile(caminhoTile, naocolidivel);
	mapaTiles[3] = pTile;
	pTile = new Tile(caminhoTile, espinho);
	mapaTiles[1] = pTile;
	pTile = new Tile(caminhoTile, porta);
	mapaTiles[2] = pTile;
}