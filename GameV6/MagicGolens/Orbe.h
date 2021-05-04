#pragma once
#include <math.h>
#include "Arremessavel.h"
class Orbe : public Arremessavel
{
private:

public:
	Orbe(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL, ListaEntidades* lista = NULL, GerenciadorColisoes* Gc = NULL);
	~Orbe();

	void atualizar();
};
