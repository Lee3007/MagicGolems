#pragma once
#include "Inimigo.h"
#include "Atirador.h"
#include "Jogador.h"
#include "CristalGelo.h"

class GolemGelo :
	public Inimigo, public Atirador
{
private:
	float tamanhoCristal;

public:
	GolemGelo(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, float tamCristal = 1);
	~GolemGelo();
	void atualizar();
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void arremessarCristal();
};
