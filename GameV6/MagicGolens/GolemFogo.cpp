#include "stdafx.h"
#include "GolemFogo.h"

GolemFogo::GolemFogo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	aceleracao(1.6f)
{
}

GolemFogo::~GolemFogo()
{
}

void GolemFogo::atualizar()
{
	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemFogo::desenhar()
{
	janela->draw(corpo);
}

void GolemFogo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == jogador)
	{
		if (nivel <= 5)
		{
			velocidade *= aceleracao;
			nivel++;
		}
	}

	if (IdOutro == orb)
	{
		hp -= 100;
		if (hp <= 0)
			destruir = true;
	}
}