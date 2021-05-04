#pragma once
#include <math.h>
#include "Arremessavel.h"
class Orbe : public Arremessavel
{
private:
	sf::Vector2f posMouseJanela;	//posicao do mouse na janela

public:
	Orbe(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL, Entidade* eAt = NULL);
	~Orbe();

	void calcPosMouse();
	void calcPosEntAt();
	void calcMiraNorm();
	void setVelDir();
	void executar();

	void atualizar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro) {};
};
