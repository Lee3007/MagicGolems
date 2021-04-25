#include "stdafx.h"
#include "Jogo.h"

//Construtora e Destrutora

Jogo::Jogo():
GerenciadorEstado(),
GerenciadorGrafico(),
GerenciadorAtualizacoes(),
menu(&GerenciadorEstado, &GerenciadorGrafico),
fasePedra("mapas/fase3/icetiles.png", "mapas/fase3/mapa3Copy.txt", sf::Vector2f(2720.f, 2710.f)),
faseFogo("mapas/fase3/icetiles.png", "mapas/fase3/mapa3Copy.txt", sf::Vector2f(2720.f, 2710.f)),
faseGelo("mapas/fase3/icetiles.png", "mapas/fase3/mapa3Copy.txt", sf::Vector2f(2720.f, 2710.f))
{
	string caminhoTextura = "text/fallenAngel.png";
	cout << caminhoTextura << endl;
	jogador1 = new Jogador(sf::Vector2f(96.f, 144.f), sf::Vector2f(400.f,400.f), sf::Vector2f(0.f, 0.f), caminhoTextura);

	inicializarGerenciadores();
	fasePedra.setJogadores(jogador1, NULL);
	faseFogo.setJogadores(jogador1, NULL);
	faseGelo.setJogadores(jogador1, NULL);
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
	GerenciadorGrafico.setGerenciadorEstado(&GerenciadorEstado);
	GerenciadorGrafico.setJogador(jogador1);

	//GerenciadorEstado
	GerenciadorEstado.setMenu(&menu);
	GerenciadorEstado.setGerenciadores(&GerenciadorGrafico, &GerenciadorAtualizacoes);
	GerenciadorEstado.setFases(&fasePedra, &faseFogo, &faseGelo);
}
