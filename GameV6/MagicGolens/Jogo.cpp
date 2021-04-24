#include "stdafx.h"
#include "Jogo.h"

//Construtora e Destrutora

Jogo::Jogo():
GerenciadorEstado(),
GerenciadorGrafico(),
GerenciadorAtualizacoes(),
menu(&GerenciadorEstado, &GerenciadorGrafico),
fasePedra(1)
{
	string caminhoTextura = "text/fallenAngel.png";
	cout << caminhoTextura << endl;
	jogador1 = new Jogador(sf::Vector2f(100.f, 100.f), sf::Vector2f(400.f,400.f), sf::Vector2f(0.f, 0.f), caminhoTextura);

	inicializarGerenciadores();
	fasePedra.setJogadores(jogador1, NULL);
}

Jogo::~Jogo()
{
}

//Funcoes

void Jogo::executarJogo()
{
	while (GerenciadorGrafico.janelaExecutando())
	{
		GerenciadorEstado.verificaEstado();

		GerenciadorAtualizacoes.relogioRestart();

		GerenciadorGrafico.setEvento();
		
		GerenciadorGrafico.limpar();

		GerenciadorAtualizacoes.atualizar();

		GerenciadorGrafico.desenhar();

		GerenciadorGrafico.renderizar();
	}
}

void Jogo::inicializarGerenciadores()
{
	//GerenciadorAtualizacoes
	GerenciadorAtualizacoes.setGerenciador(&GerenciadorEstado);

	//GerenciadorGrafico
	GerenciadorGrafico.setMenu(&menu);
	GerenciadorGrafico.setGerenciador(&GerenciadorEstado);

	//GerenciadorEstado
	GerenciadorEstado.setGerenciadores(&GerenciadorGrafico, &GerenciadorAtualizacoes);
	GerenciadorEstado.setFases(&fasePedra, NULL, NULL);
}
