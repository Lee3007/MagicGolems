#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(ID, tam, p, v, caminhoTextura, t, j)
{
}

void GolemGelo::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}

void GolemGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	if (IdOutro == jogador)
	{
		velocidade.x += 10.f;
		velocidade.y += 10.f;
	}
}
