#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Personagem(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(),
	lentidao(1),
	vivo(false),
	podePular(true),
	alturaPulo(150),
	viradoDir(true)
{
}

Jogador::~Jogador()
{
}

void Jogador::desenhar()
{
	janela->draw(corpo);
}

void Jogador::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	sf::Vector2f dist = posicao - posicaoOutro;
	sf::Vector2f invasao;

	if (IdOutro == bloco)
	{
		lentidao = 1;
	}

	if (IdOutro == areia)
	{
		lentidao = 3;

		cout << "Areia" << endl;
	}
	else if (IdOutro == fogo)
		cout << "Fogo" << endl;
	else if (IdOutro == golemPedra)
	{
		morrer();
	}
}

void Jogador::morrer()
{
	vivo = false;
}

bool Jogador::estaVivo()
{
	return vivo;
}

void Jogador::reiniciar()
{
	velocidade = sf::Vector2f(0.f, 0.f);
	vivo = true;
}

void Jogador::setPulo(bool b)
{
	podePular = b;
}
