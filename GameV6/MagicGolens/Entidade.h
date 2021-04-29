#pragma once
#include "stdafx.h"

class Entidade
{
protected:
	sf::Texture textura;
	sf::Vector2f posicao;
	sf::Vector2f velocidade;
	sf::RectangleShape corpo;
	sf::RenderWindow* janela;
	float* dt;
	
public:

	//Construtora e Destrutora
	Entidade(sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Entidade();

	//Funcoes
	virtual void atualizar() = 0;
	virtual void desenhar() = 0;
	void setPosicao(sf::Vector2f p);
	sf::Vector2f getPosicao();
};