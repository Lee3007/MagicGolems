#pragma once
#include "Personagem.h"
#include "Orbe.h"
#include <vector>
#include "Atirador.h"

class Jogador :
	public Personagem, public Atirador
{
private:
	float lentidao;
	bool vivo;
	bool podePular;
	bool podeAtirar;
	float alturaPulo;
	float cooldown;

public:

	//Construtora e Destrutora
	Jogador(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(60.f, 90.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
	~Jogador();

	//Funcoes
	void atualizar();
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro);
	void morrer();
	bool estaVivo();
	void reiniciar();
	void possoAtirar(float t);
};
