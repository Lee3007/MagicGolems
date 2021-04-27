#include "stdafx.h"
#include "Fase.h"

Fase::Fase(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto) :
LEntidades(),
statusConcluida(false),
pontoFinal(ponto)
{
	jogador1 = NULL;
	jogador2 = NULL;
	pTile = new Tile(caminhoTile);
	pMapa = new Mapa(caminhoMapa);
	pGm = new GerenciadorMapa(pMapa, pTile);	
	LEntidades = new ListaEntidades();

	if (!backgroundText.loadFromFile(caminhoBackground)) {
		cout << "Erro, nao pode abrir a Textura" << endl;
		exit(404);
	}

	backgroundSpr.setTexture(backgroundText);
	backgroundSpr.setPosition( sf::Vector2f( 0.f, 0.f ) );
	backgroundSpr.setScale(sf::Vector2f( 1.f, 1.f ) );

	pGm->setBackground(&backgroundSpr);

}

Fase::~Fase()
{
	delete (pTile);
	pTile = NULL;
	delete (pMapa);
	pMapa = NULL;
	delete (pGm);
	pGm = NULL;
}

void Fase::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;

	if (j1 != NULL)
	{
		float x;
		float y;

		sf::Vector2f p = getPosicaoJogador();

		x = p.x;
		y = p.y;

		cout << "Jogador recebido pela fase com sucesso" << endl;
		cout << "xo = " << x << endl << "yo = " << y << endl;
	}

	LEntidades->incluirEntidade(j1);

	if (j2 != NULL)
	{
		LEntidades->incluirEntidade(j2);
	}
		
}

void Fase::reiniciarFase()
{
	cout << "Meu tamanho antes de entrar : " << LEntidades->getTamanho() << endl;

	if (!LEntidades->getVaziaStatus())
	{
		cout << "Entrei no reiniciar" << endl;
		LEntidades->removerEntidade(jogador1);

		if (jogador2 != NULL)
			LEntidades->removerEntidade(jogador2);

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