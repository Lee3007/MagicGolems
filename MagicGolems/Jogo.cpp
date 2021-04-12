#include "stdafx.h"
#include "Jogo.h"

//Construtora e Destrutora

Jogo::Jogo():
GerenciadorGrafico(),
GerenciadorAtualizacoes()
{
	jogador = new Jogador(sf::Vector2f(0.f,0.f), sf::Vector2f(0.f, 0.f));
	relogio = GerenciadorGrafico.getRelogio();
	LEntidades.incluirEntidade(jogador);
	GerenciadorGrafico.setListaEntidades(&LEntidades);
	GerenciadorAtualizacoes.setListaEntidades(&LEntidades);
}

Jogo::~Jogo()
{
}

//Funcoes

void Jogo::executarJogo()
{
	relogio->restart();


	while (GerenciadorGrafico.janelaExecutando())
	{
		sf::Time tempo = relogio->getElapsedTime();

		if (GerenciadorGrafico.setEvento())
		{
			if (GerenciadorGrafico.fechouJanela())
			{
				GerenciadorGrafico.fecharJanela();
			}
		}
		
		GerenciadorGrafico.limpar();

		GerenciadorAtualizacoes.atualizar(tempo.asSeconds());

		GerenciadorGrafico.desenhar();

		GerenciadorGrafico.renderizar();
		relogio->restart();
	}
}
