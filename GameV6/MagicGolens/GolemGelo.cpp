#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Personagem(ID, tam, p, v, caminhoTextura, t, j)
{
}

void GolemGelo::atualizar()
{
	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}

void GolemGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	if (IdOutro == bloco || IdOutro == espinho || IdOutro == porta)
	{
		sf::Vector2f dist = posicao - posicaoOutro;
		sf::Vector2f invasao;

		invasao.x = fabsf(dist.x) - ((dimensoesOutro.x) / 2 + (dimensoes.x) / 2);
		invasao.y = fabsf(dist.y) - ((dimensoesOutro.y) / 2 + (dimensoes.y) / 2);

		if (invasao.x < 0.f && invasao.y < 0.f)
		{
			if (fabsf(invasao.x) < fabsf(invasao.y))
			{
				if (dist.x > 0.f)
				{
					posicao.x = posicao.x + fabsf(invasao.x);
					corpo.setPosition(posicao);
					velocidade.x = (-1) * velocidade.x;
					corpo.setScale(sf::Vector2f(1.f, 1.f));
				}
				else
				{
					posicao.x = posicao.x - fabsf(invasao.x);
					corpo.setPosition(posicao);
					velocidade.x = (-1) * velocidade.x;
					corpo.setScale(sf::Vector2f(-1.f, 1.f));
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicao.y = posicao.y + fabsf(invasao.y);
					corpo.setPosition(posicao);
					velocidade.y = 0.f;
				}
				else
				{
					posicao.y = posicao.y - fabsf(invasao.y);
					corpo.setPosition(posicao);
					velocidade.y = 0.f;
				}
			}
		}
	}
}