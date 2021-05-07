#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, float tamCristal) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(3),
	tamanhoCristal(tamCristal)
{
}

void GolemGelo::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (podeAtirar)
	{
		arremessarCristal();
		cooldown = 0.f;
		podeAtirar = false;
	}

	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);

}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}

void GolemGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
}

void GolemGelo::arremessarCristal()
{
	CristalGelo* pCristal = NULL;
	pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f)* tamanhoCristal, posicao, sf::Vector2f(300.f, -300.f), "text/cristal.png", dt, janela);
	LEntidades->incluirEntidade(pCristal);
	GColisoes->adicionarEntidade(pCristal);
}
