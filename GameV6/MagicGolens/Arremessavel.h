#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"

class Arremessavel : public Entidade
{
protected:

	ListaEntidades* LEntidades;
	GerenciadorColisoes* GColisoes;

public:
	Arremessavel(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL, ListaEntidades* lista = NULL, GerenciadorColisoes* Gc = NULL);
	~Arremessavel();

	virtual void atualizar() = 0;
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro);
};
