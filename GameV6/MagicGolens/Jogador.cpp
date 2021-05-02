#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(ID, tam, p, v, caminhoTextura, t, j)
{
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
	velocidade.x = 0.f;
	velocidade.y = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 400.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -400.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		velocidade.y = -400.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		velocidade.y = 400.f;
	}

	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void Jogador::desenhar()
{
	janela->draw(corpo);
}

void Jogador::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	sf::Vector2f dist = posicao - posicaoOutro;
	sf::Vector2f invasao;

	if (IdOutro == chao || IdOutro == parede)
	{

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
					cout << "invasao lateral direita" << endl;
				}
				else
				{
					posicao.x = posicao.x - fabsf(invasao.x);
					corpo.setPosition(posicao);
					cout << "invasao lateral esquerda" << endl;
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicao.y = posicao.y + fabsf(invasao.y);
					corpo.setPosition(posicao);
					cout << "invasao vertical por baixo" << endl;
				}
				else
				{
					posicao.y = posicao.y - fabsf(invasao.y);
					corpo.setPosition(posicao);
					cout << "invasao vertical por cima" << endl;
				}
			}
		}

		//cout << "Bloco" << endl;
	}
	else if (IdOutro == areia)
		cout << "Areia" << endl;
	else
		cout << "INIMIGO!" << endl;
}
