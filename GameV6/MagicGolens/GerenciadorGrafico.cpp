#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"
#include "Menu.h"

//Construtora e Destrutora

GerenciadorGrafico::GerenciadorGrafico():
janela(sf::VideoMode(1280,720), "MagicGolens"),
evento()
{
	GEstado = NULL;
	menu = NULL;
	LEntidades = NULL;
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
