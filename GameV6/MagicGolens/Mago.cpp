#include "stdafx.h"
#include "Mago.h"

Mago::Mago(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Jogador(ID, tam, p, v, caminhoTextura, t, j)
{
}

void Mago::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 600.f / lentidao;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -600.f / lentidao;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && podeAtirar) {
		podeAtirar = false;
		Orbe* pOrbe = NULL;

		pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(800.f, 0.f), "text/orbe.png", dt, janela, LEntidades, GColisoes);
		GColisoes->adicionarEntidade(pOrbe);
		LEntidades->incluirEntidade(pOrbe);

		cooldown = 0.f;
	}

	velocidade.y += 98.1f;
	velocidade.x *= 0.8f;

	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}
