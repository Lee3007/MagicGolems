#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"
#include "Menu.h"

//Construtora e Destrutora

GerenciadorGrafico::GerenciadorGrafico():
janela(sf::VideoMode(1280,720), "MagicGolens"),
evento(),
view(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(1920.0f, 1080.0f))
{
	GEstado = NULL;
	menu = NULL;
	LEntidades = NULL;
	GMapa = NULL;
	jogador = NULL;
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	GEstado = NULL;
}

//Funcoes

void GerenciadorGrafico::desenhar()
{
	if (GEstado->menuAtivo())
	{
		menu->desenhar(&janela);
	}
	else
	{
		Entidade* pEntidade = NULL;
		GMapa->desenhar(&janela);
		atualizaView();

		for (int i = 0; i < LEntidades->getTamanho(); i++)
		{
			pEntidade = LEntidades->operator[](i);
			pEntidade->desenhar(&janela);
		}
	}
}

void GerenciadorGrafico::setListaEntidades(ListaEntidades* L)
{
	LEntidades = L;
}

void GerenciadorGrafico::setMenu(Menu* m)
{
	if(m != NULL)
		menu = m;
	else
	{
		cout << "ERRO: Gerenciador grafico nao recebeu menu corretamente" << endl;
		exit(823);
	}
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

void GerenciadorGrafico::setGerenciador(GerenciadorEstado* Ge)
{
	if (Ge != NULL)
		GEstado = Ge;
	else
	{
		cout << "Gerenciador grafico nao recebeu o gerenciador estado corretamente" << endl;
	}
}

void GerenciadorGrafico::setEvento()
{
	if (janela.pollEvent(evento))
	{
		if (clickX())
			fecharJanela();

		if (GEstado->menuAtivo())
		{
			switch (evento.type)
			{
			case sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Up:
					menu->moverCima();
					break;

				case sf::Keyboard::Down:
					menu->moverBaixo();
					break;

				case sf::Keyboard::Return:
					menu->executarEnter();
					break;
				}
			}
		}
		else
		{
			switch (evento.type)
			{
			case sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Escape:
					GEstado->setMenuStatus(true);
					break;
				}
			}
		}
	}
}

bool GerenciadorGrafico::janelaExecutando()
{
	return janela.isOpen();
}

bool GerenciadorGrafico::clickX()
{
	if (evento.type == sf::Event::Closed)
	{
		return true;
	}
	else
		return false;
}

void GerenciadorGrafico::setGerenciadorMapa(GerenciadorMapa* Gm) {
	GMapa = Gm;
}

void GerenciadorGrafico::setJogador(Jogador* jog) {
	jogador = jog;
}

void GerenciadorGrafico::atualizaView()
{
	sf::Vector2f posicao_view = jogador->getPosicao();

	if (posicao_view.x >= 960.f)
	{
		view.setCenter(jogador->getPosicao());
		janela.setView(view);
	}


}