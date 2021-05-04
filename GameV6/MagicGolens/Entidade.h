#pragma once
#include "stdafx.h"
#include "IdsColidiveis.h"

class Entidade
{
protected:
	const IdsColidiveis Id;
	sf::Texture textura;
	sf::Vector2f posicao;
	sf::Vector2f velocidade;
	sf::Vector2f dimensoes;
	sf::RectangleShape corpo;
	sf::RenderWindow* janela;
	float* dt;

public:

	//Construtora e Destrutora
	Entidade(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Entidade();

	//Funcoes
	virtual void atualizar() = 0;
	virtual void desenhar() = 0;
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro) = 0;
	void setPosicao(sf::Vector2f p);
	sf::Vector2f getPosicao();
	sf::Vector2f getDimensoes();
	const IdsColidiveis getId();
};