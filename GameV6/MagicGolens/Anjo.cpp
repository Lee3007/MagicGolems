#include "stdafx.h"
#include "Anjo.h"

Anjo::Anjo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Jogador(ID, tam, p, v, caminhoTextura, t, j)
{
}

Anjo::~Anjo()
{
}

void Anjo::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		velocidade.x = 600.f / lentidao;
		corpo.setScale(sf::Vector2f(1.f, 1.f));
		viradoDir = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		velocidade.x = -600.f / lentidao;
		corpo.setScale(sf::Vector2f(-1.f, 1.f));
		viradoDir = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && podeAtirar) {
		podeAtirar = false;
		Orbe* pOrbe = NULL;

		if (viradoDir)
			pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(800.f, 0.f), "text/orbe.png", dt, janela, LEntidades, GColisoes);
		else
			pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(-800.f, 0.f), "text/orbe.png", dt, janela, LEntidades, GColisoes);

		GColisoes->adicionarEntidade(pOrbe);
		LEntidades->incluirEntidade(pOrbe);

		cooldown = 0.f;
	}

	velocidade.y += 98.1f;
	velocidade.x *= 0.8f;

	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}
