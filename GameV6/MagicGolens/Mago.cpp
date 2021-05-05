#include "stdafx.h"
#include "Mago.h"

Mago::Mago(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Jogador(ID, tam, p, v, caminhoTextura, t, j),
pontuacao(10000),
penalidadeAnte(1),
penalidadeAtual(1)
{
}

Mago::~Mago() {}

void Mago::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 600.f / lentidao;
		corpo.setScale(sf::Vector2f(1.f, 1.f));
		viradoDir = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -600.f / lentidao;
		corpo.setScale(sf::Vector2f(-1.f, 1.f));
		viradoDir = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && podeAtirar) {
		podeAtirar = false;
		Orbe* pOrbe = NULL;

		if(viradoDir)
			pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(800.f, 0.f), "text/orbe.png", dt, janela, LEntidades, GColisoes);
		else
			pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(-800.f, 0.f), "text/orbe.png", dt, janela, LEntidades, GColisoes);


		GColisoes->adicionarEntidade(pOrbe);
		LEntidades->incluirEntidade(pOrbe);

		cooldown = 0.f;
	}

	velocidade.y += 98.1f;
	velocidade.x *= 0.8f;

	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void Mago::aumentaPenalidade()
{
	//A pontuacao do jogador comecara em 10,000 pontos, e irá receber penalidades a cada morte. A penalidade seguirá a sequencia de Fibonacci
	int aux = penalidadeAtual;
	penalidadeAtual += penalidadeAnte;
	penalidadeAnte = aux;
	pontuacao = pontuacao / penalidadeAtual;
}

float Mago::getPontuacao()
{
	return pontuacao;
}

int Mago::getPenalidadeAtual()
{
	return penalidadeAtual;
}

int Mago::getPenalidadeAnte()
{
	return penalidadeAnte;
}
