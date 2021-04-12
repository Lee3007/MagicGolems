#include "stdafx.h"
#include "GerenciadorGrafico.h"

//Construtora e Destrutora

GerenciadorGrafico::GerenciadorGrafico():
janela(sf::VideoMode(800,600), "MagicGolens"),
evento(),
relogio(),
janelaAberta(true)
{
	LEntidades = NULL;
	relogio.restart();
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

//Funcoes

void GerenciadorGrafico::desenhar()
{
	int i = 0;
	Entidade* pEntidade = NULL;

	for (i = 0; i < LEntidades->getTamanho(); i++)
	{
		pEntidade = LEntidades->operator[](i);
		pEntidade->desenhar(&janela);
	}
}

void GerenciadorGrafico::setListaEntidades(ListaEntidades* L)
{
	LEntidades = L;
}

void GerenciadorGrafico::fecharJanela()
{
	janela.close();
}

void GerenciadorGrafico::limpar()
{
	janela.clear();
}

void GerenciadorGrafico::renderizar()
{
	janela.display();
}

bool GerenciadorGrafico::setEvento()
{
	return janela.pollEvent(evento);
}

bool GerenciadorGrafico::janelaExecutando()
{
	return janelaAberta;
}

bool GerenciadorGrafico::fechouJanela()
{
	if (evento.type == sf::Event::Closed)
	{
		janelaAberta = false;
		return true;
	}
	else
		return false;
}

sf::Clock* GerenciadorGrafico::getRelogio()
{
	return &relogio;
}
