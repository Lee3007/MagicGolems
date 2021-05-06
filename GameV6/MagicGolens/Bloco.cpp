#include "stdafx.h"
#include "Bloco.h"

Bloco::Bloco(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Tile(ID, tam, p, v, caminhoTextura, t, j)
{
}

Bloco::~Bloco()
{
}

void Bloco::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
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
				//cout << "invasao lateral direita" << endl;	//B <- P
				velocidade.x = 0.f;
			}
			else
			{
				posicao.x = posicao.x - fabsf(invasao.x);
				corpo.setPosition(posicao);
				//cout << "invasao lateral esquerda" << endl;	// P -> B
				velocidade.x = 0.f;
			}
		}
		else
		{
			if (dist.y > 0.f)
			{
				posicao.y = posicao.y + fabsf(invasao.y);
				corpo.setPosition(posicao);
				//cout << "invasao vertical por baixo" << endl;
				velocidade.y = 0.f;
			}
			else
			{
				posicao.y = posicao.y - fabsf(invasao.y);
				corpo.setPosition(posicao);
				//cout << "invasao vertical por cima" << endl;
				velocidade.y = 0.f;
			}
		}
	}

	//cout << "Bloco" << endl;
}
