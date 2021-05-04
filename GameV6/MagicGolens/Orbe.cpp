#include "stdafx.h"
#include "Orbe.h"

Orbe::Orbe(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, ListaEntidades* lista, GerenciadorColisoes* Gc) :
	Arremessavel(ID, tam, p, v, caminhoTextura, t, j, lista, Gc)
{
}

Orbe::~Orbe()
{
}

void Orbe::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}