#include "stdafx.h"
#include "Orbe.h"

Orbe::Orbe(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, Entidade* eAt) :
	Arremessavel(ID, tam, p, v, caminhoTextura, t, j, eAt),
	posMouseJanela(sf::Vector2f(0.f, 0.f))
{
}

Orbe::~Orbe()
{
}

void Orbe::calcPosMouse()
{
	posMouseJanela = sf::Vector2f(sf::Mouse::getPosition(*janela));
	cout << posMouseJanela.x << " " << posMouseJanela.y << endl;
}

void Orbe::calcPosEntAt()
{
	posOrigem = enteAtirador->getPosicao();
}

void Orbe::calcMiraNorm()
{
	float aux;
	dirMira = posMouseJanela - posOrigem;
	aux = sqrt(pow(dirMira.x, 2) + pow(dirMira.y, 2));
	dirMiraNorm = dirMira / aux;
}

void Orbe::setVelDir()
{
	velDir = dirMiraNorm * 5.f;
}

void Orbe::executar()
{
	calcPosMouse();
	calcPosEntAt();
	calcMiraNorm();
	setVelDir();
}

void Orbe::atualizar()
{
	posicao += velDir;
	corpo.setPosition(posicao);
}