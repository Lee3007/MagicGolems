#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, string caminhoCongelado) :
	Personagem(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(),
	lentidao(1),
	vivo(false),
	podePular(true),
	alturaPulo(150),
	tempoCongelamento(1.5),
	congelado(0),
	cooldownGelo(4)
{
	if (!texturaCongelado.loadFromFile(caminhoCongelado))
		exit(9999);
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
	lentidao = 1;
	if (IdOutro == areia)
	{
		lentidao = 4;
	}
	if (IdOutro == fogo) {
		limite += 0.4;
		morrer();
	}
	if (IdOutro == espinho) {
		morrer();
	}

	if (IdOutro == estalactite) {
		morrer();
	}

	if (IdOutro == golemPedra)
	{
		morrer();
	}
	if (IdOutro == golemFogo)
	{
		morrer();
		limite += 0.4;
	}
	if (IdOutro == golemGelo)
	{
		cooldownGelo = 3.f;
		morrer();
	}
	if (IdOutro == cristal) {
		cooldownGelo = 0.f;
		congelar();
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

void Jogador::reiniciarTudo()
{
	limite = 0.5f;
	velocidade = sf::Vector2f(0.f, 0.f);
	vivo = true;
}

void Jogador::setPulo(bool b)
{
	podePular = b;
}

void Jogador::congelar()
{
	corpo.setTexture(&texturaCongelado);
	congelado = true;
	if (viradoDir)
		velocidade.x = 600;
	else if (!viradoDir)
		velocidade.x = -600;
}

void Jogador::descongelado(float t) {
	if (t >= tempoCongelamento) {
		corpo.setTexture(&textura);
		congelado = false;
	}

}