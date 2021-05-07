#include "stdafx.h"
#include "GolemPedra.h"

GolemPedra::GolemPedra(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	crescimento(1.2f),
	cura(100.f)
{
}

GolemPedra::~GolemPedra()
{
}

void GolemPedra::atualizar()
{
	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemPedra::desenhar()
{
	janela->draw(corpo);
}

void GolemPedra::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == jogador)
	{
		if (nivel <= 3)
		{
			hp += cura;
			dimensoes *= crescimento;
			corpo.scale(sf::Vector2f(crescimento, crescimento));
			nivel++;
		}
	}

	if (IdOutro == orb)
	{
		destruir = true;
	}
}