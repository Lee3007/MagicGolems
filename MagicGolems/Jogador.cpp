#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(sf::Vector2f p, sf::Vector2f v):
Personagem(p, v)
{
}

Jogador::~Jogador()
{
}

void Jogador::atualizar(float t)
{
	cout << "px = " << posicao.x << endl;
	cout << "py = " << posicao.y << endl;

	velocidade.x = 0.f;
	velocidade.y = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 100000.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -100000.f;
	}

	posicao += velocidade * t;
	corpo.setPosition(posicao);
}

void Jogador::desenhar(sf::RenderWindow* j)
{
	j->draw(corpo);
}
