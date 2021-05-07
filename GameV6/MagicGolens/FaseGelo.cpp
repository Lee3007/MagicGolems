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
		float px = static_cast<float>(rand() % 2400 + 200);
		float py = static_cast<float>(rand() % 2400 + 200);

		GolemGelo* pGolemGelo = new GolemGelo(golemGelo, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(80.f, 80.f), "text/golemGelov2.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pGolemGelo);
		GColisoes->adicionarEntidade(pGolemGelo);
		pGolemGelo->setListaEntidades(LEntidades);
		pGolemGelo->setGerenciadorColisoes(GColisoes);
	}

	GolemGelo* pGolemGelo = new GolemGelo(golemGelo, sf::Vector2f(288.f, 432.f), sf::Vector2f(1920.f, 2060.f), sf::Vector2f(0.f, 0.f), "text/golemGelov2.png", dt, janela, jogador1, jogador2);
	LEntidades->incluirEntidade(pGolemGelo);
	GColisoes->adicionarEntidade(pGolemGelo);
	pGolemGelo->setListaEntidades(LEntidades);
	pGolemGelo->setGerenciadorColisoes(GColisoes);
}

void FaseGelo::criarObstaculos()
{
	int qntd;
	float px;

	qntd = rand() % 5 + 1;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 2000);
		Estalactite* pEst = NULL;
		pEst= new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(200.f + px, 96.3f + 100/2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 1;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 384);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(192.f + px, 672.3f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 1;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 864);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(192.f + px, 1824.3f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}
}

void FaseGelo::inicializarTiles(const char* caminhoTile)
{
	Tile* pTile = NULL;

	pTile = new Bloco(bloco, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[0] = pTile;
	pTile = new Ar(naocolidivel, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[3] = pTile;
	pTile = new Espinho(espinho, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[1] = pTile;
	pTile = new Porta(porta, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[2] = pTile;
}