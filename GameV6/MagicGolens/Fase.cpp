#include "stdafx.h"
#include "Fase.h"

Fase::Fase(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	LEntidades(),
	statusConcluida(false),
	pontoFinal(ponto),
	mapaTiles()
{
	dt = t;
	janela = j;
	jogador1 = NULL;
	jogador2 = NULL;
	GColisoes = NULL;
	LEntidades = new ListaEntidades();
	pGm = NULL;
	pMapa = NULL;
	pTile = NULL;

	this->caminhoTile = caminhoTile;
	this->caminhoMapa = caminhoMapa;
	this->caminhoBackground = caminhoBackground;
}

Fase::~Fase()
{
	pTile = NULL;
	delete (pMapa);
	pMapa = NULL;
	delete (pGm);
	pGm = NULL;
}

void Fase::criarMapa()
{
	inicializarTiles(caminhoTile);

	pMapa = new Mapa(caminhoMapa);
	pGm = new GerenciadorMapa(mapaTiles, pMapa, janela);

	if (!backgroundText.loadFromFile(caminhoBackground)) {
		cout << "Erro, nao pode abrir a Textura" << endl;
		exit(404);
	}

	backgroundSpr.setTexture(backgroundText);
	backgroundSpr.setPosition(sf::Vector2f(0.f, 0.f));
	backgroundSpr.setScale(sf::Vector2f(1.f, 1.f));

	pGm->setBackground(&backgroundSpr);
}

void Fase::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;

	if (jogador1 != NULL)
	{
		cout << "Jogador recebido pela fase com sucesso" << endl;
	}

	jogador1->setGerenciadorColisoes(GColisoes);
	jogador1->setListaEntidades(LEntidades);
	LEntidades->incluirEntidade(j1);

	if (jogador2 != NULL)
	{
		cout << "Jogador 2 recebido pela fase com sucesso" << endl;
		LEntidades->incluirEntidade(j2);
		jogador2->setGerenciadorColisoes(GColisoes);
		jogador2->setListaEntidades(LEntidades);
	}
}

void Fase::inicializarFase(Jogador* j1, Jogador* j2)
{
	setJogadores(j1, j2);

	jogador1->reiniciar();
	GColisoes->adicionarEntidade(jogador1);

	if (jogador2 != NULL)
	{
		j2->reiniciar();
		GColisoes->adicionarEntidade(j2);
	}

	GColisoes->setListaEntidades(LEntidades);
	criarInimigos();
	setPosicaoJogadores();
}

void Fase::reiniciarFase()
{
	statusConcluida = false;
	if (!LEntidades->getVaziaStatus())
	{
		LEntidades->removerEntidade(jogador1);
		cout << "jogador 1 removido" << endl;

		if (jogador2 != NULL)
		{
			LEntidades->removerEntidade(jogador2);
			cout << "jogador 2 removido" << endl;
		}

		jogador1 = NULL;
		jogador2 = NULL;

		LEntidades->destruirEntidades();
	}
}

void Fase::setConcluida(bool b)
{
	statusConcluida = b;
}

const bool Fase::getStatus() const
{
	return statusConcluida;
}

ListaEntidades* Fase::getListaEntidades()
{
	return LEntidades;
}

sf::Vector2f Fase::getPosicaoJogador() const
{
	return jogador1->getPosicao();
}

const sf::Vector2f Fase::getPontoFinal() const
{
	return pontoFinal;
}

GerenciadorMapa* Fase::getGerenciadorMapa() {
	return pGm;
}

void Fase::setGerenciadorColisoes(GerenciadorColisoes* pg)
{
	GColisoes = pg;
}

bool Fase::jogadorMorto()
{
	if (!jogador1->estaVivo())
		return true;
	if (jogador2 != NULL)
		if (!jogador2->estaVivo())
			return true;

	return false;
}