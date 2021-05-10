#pragma once
#include "Fase.h"
#include "Chefao.h"

class FaseGelo :
	public Fase
{
private:

public:
	FaseGelo(const char* caminhoTile = "", const char* caminhoMapa = "", const char* caminhoBackground = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f), float* t = NULL, sf::RenderWindow* j = NULL);
	~FaseGelo();
	void setPosicaoJogadores();
	const sf::Vector2f getPontoFinal() const;
	void criarInimigos();
	void criarObstaculos();
	void inicializarTiles(const char* caminhoTile);
	void recuperarEntes();
};