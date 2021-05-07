#include "stdafx.h"
#include "Areia.h"
#include "Jogador.h"

Areia::Areia(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Obstaculo(ID, tam, p, v, caminhoTextura, t, j)
{
}

Areia::~Areia()
{
}

void Areia::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	sf::Vector2f dist = posicaoOutro - posicao;
	sf::Vector2f invasao;

	invasao.x = fabsf(dist.x) - ((dimensoesOutro.x) / 2 + (dimensoes.x) / 2);
	invasao.y = fabsf(dist.y) - ((dimensoesOutro.y) / 2 + (dimensoes.y) / 2);

	if(IdOutro == jogador)
	{
		if (invasao.x < 0.f && invasao.y < 0.f)
		{
			if (fabsf(invasao.x) < fabsf(invasao.y))
			{

				if (dist.x > 0.f)
				{
					posicaoOutro.x = posicaoOutro.x + fabsf(invasao.x);
					e->setPosicao(posicaoOutro);
					//cout << "invasao lateral direita" << endl;	//B <- P
					e->setVelocidadeX(0.f);
				}
				else
				{
					posicaoOutro.x = posicaoOutro.x - fabsf(invasao.x);
					e->setPosicao(posicaoOutro);
					//cout << "invasao lateral esquerda" << endl;	// P -> B
					e->setVelocidadeX(0.f);
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicaoOutro.y = posicaoOutro.y + fabsf(invasao.y);
					e->setPosicao(posicaoOutro);
					//cout << "invasao vertical por baixo" << endl;
					e->setVelocidadeY(0.f);
				}
				else
				{
					posicaoOutro.y = posicaoOutro.y - fabsf(invasao.y);
					e->setPosicao(posicaoOutro);
					//cout << "invasao vertical por cima" << endl;
					e->setVelocidadeY(0.f);
				}
			}
		}
	}

	else if(IdOutro == golemPedra)
	{
		if (invasao.x < 0.f && invasao.y < 0.f)
		{
			if (fabsf(invasao.x) < fabsf(invasao.y))
			{

				if (dist.x > 0.f)
				{
					posicaoOutro.x = posicaoOutro.x + fabsf(invasao.x);
					e->setPosicao(posicaoOutro);
					//cout << "invasao lateral direita" << endl;	//B <- P
				}
				else
				{
					posicaoOutro.x = posicaoOutro.x - fabsf(invasao.x);
					e->setPosicao(posicaoOutro);
					//cout << "invasao lateral esquerda" << endl;	// P -> B
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicaoOutro.y = posicaoOutro.y + fabsf(invasao.y);
					e->setPosicao(posicaoOutro);
					//cout << "invasao vertical por baixo" << endl;
					e->setVelocidadeY(0.f);
				}
				else
				{
					posicaoOutro.y = posicaoOutro.y - fabsf(invasao.y);
					e->setPosicao(posicaoOutro);
					//cout << "invasao vertical por cima" << endl;
					e->setVelocidadeY(0.f);
				}
			}
		}
	}
}
