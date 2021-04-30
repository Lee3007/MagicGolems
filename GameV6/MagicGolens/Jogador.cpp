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
	cout << "AI!" << endl;
}
