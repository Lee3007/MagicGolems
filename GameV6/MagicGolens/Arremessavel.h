#pragma once
#include "Entidade.h"
class Arremessavel : public Entidade
{
protected:

	Entidade* enteAtirador;
	sf::Vector2f posOrigem;			//Posicao da Entidade, que será a origem do orbe
	sf::Vector2f dirMira;			//Direção da mira (vetor)
	sf::Vector2f dirMiraNorm;		//Direção da mira normalizada -> tam 1
	sf::Vector2f velDir;

public:
	Arremessavel(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL, Entidade* eAt = NULL);
	~Arremessavel();

	virtual void atualizar() = 0;
	void desenhar();
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro) = 0;
};
