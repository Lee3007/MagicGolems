#pragma once
#include "stdafx.h"

class Entidade
{
protected:

	sf::Texture* textura;
	sf::Vector2f posicao;
	sf::Vector2f velocidade;
	sf::RectangleShape corpo;
	
public:

	//Construtora e Destrutora
	Entidade(sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f));
	~Entidade();

	//Funcoes
	virtual void atualizar(float t) = 0;
	virtual void desenhar(sf::RenderWindow *j) = 0;
};

