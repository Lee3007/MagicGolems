#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura):
Personagem(tam, p, v, caminhoTextura)
{
}

Jogador::~Jogador()
{
}

void Jogador::atualizar(float t)
{
	velocidade.x = 0.f;
	velocidade.y = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 200.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -200.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		velocidade.y = -200.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		velocidade.y = 200.f;
	}

	posicao += velocidade * t;
	corpo.setPosition(posicao);
}

void Jogador::desenhar(sf::RenderWindow* j)
{
	j->draw(corpo);
}

void Jogador::setPosicao(sf::Vector2f p)
{
	posicao = p;
	corpo.setPosition(posicao);
}

sf::Vector2f Jogador::getPosicao()
{
	return corpo.getPosition();
}
