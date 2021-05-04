#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Personagem(ID, tam, p, v, caminhoTextura, t, j),
	lentidao(1),
	vivo(false),
	podePular(true),
	alturaPulo(150),
	orbe1(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(0.f, 0.f), "text/orbe.png", dt, janela, this)
{
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 600.f / lentidao;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -600.f / lentidao;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && podePular)
	{
		podePular = false;
		velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		orbe1.setPosicao(this->getPosicao());
		orbe1.executar();

		orbes.push_back(orbe1);
	}

	velocidade.y += 98.1f;
	velocidade.x *= 0.8f;

	posicao += velocidade * (*dt);
	//posicao += velocidade * 0.02f;
	corpo.setPosition(posicao);
}

void Jogador::desenhar()
{
	janela->draw(corpo);
	desenharOrbes();
}

void Jogador::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	sf::Vector2f dist = posicao - posicaoOutro;
	sf::Vector2f invasao;

	if (IdOutro == bloco)
	{
		lentidao = 1;

		invasao.x = fabsf(dist.x) - ((dimensoesOutro.x) / 2 + (dimensoes.x) / 2);
		invasao.y = fabsf(dist.y) - ((dimensoesOutro.y) / 2 + (dimensoes.y) / 2);

		if (invasao.x < 0.f && invasao.y < 0.f)
		{
			if (fabsf(invasao.x) < fabsf(invasao.y))
			{
				if (dist.x > 0.f)
				{
					posicao.x = posicao.x + fabsf(invasao.x);
					corpo.setPosition(posicao);
					//cout << "invasao lateral direita" << endl;	//B <- P
					velocidade.x = 0.f;
				}
				else
				{
					posicao.x = posicao.x - fabsf(invasao.x);
					corpo.setPosition(posicao);
					//cout << "invasao lateral esquerda" << endl;	// P -> B
					velocidade.x = 0.f;
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicao.y = posicao.y + fabsf(invasao.y);
					corpo.setPosition(posicao);
					//cout << "invasao vertical por baixo" << endl;
					velocidade.y = 0.f;
				}
				else
				{
					posicao.y = posicao.y - fabsf(invasao.y);
					corpo.setPosition(posicao);
					//cout << "invasao vertical por cima" << endl;
					velocidade.y = 0.f;
					podePular = true;
				}
			}
		}

		//cout << "Bloco" << endl;
	}
	else if (IdOutro == areia)
	{
		lentidao = 3;
		//velocidade.y = 10.f;

		invasao.x = fabsf(dist.x) - ((dimensoesOutro.x) / 2 + (dimensoes.x) / 2);
		invasao.y = fabsf(dist.y) - ((dimensoesOutro.y) / 2 + (dimensoes.y) / 2);

		if (invasao.x < 0.f && invasao.y < 0.f)
		{
			if (fabsf(invasao.x) < fabsf(invasao.y))
			{
				if (dist.x > 0.f)
				{
					posicao.x = posicao.x + fabsf(invasao.x);
					corpo.setPosition(posicao);
					//cout << "invasao lateral direita" << endl;	//B <- P
					velocidade.x = 0.f;
				}
				else
				{
					posicao.x = posicao.x - fabsf(invasao.x);
					corpo.setPosition(posicao);
					//cout << "invasao lateral esquerda" << endl;	// P -> B
					velocidade.x = 0.f;
				}
			}
			else
			{
				if (dist.y > 0.f)
				{
					posicao.y = posicao.y + fabsf(invasao.y);
					corpo.setPosition(posicao);
					//cout << "invasao vertical por baixo" << endl;
					velocidade.y = 0.f;
				}
				else
				{
					posicao.y = posicao.y - fabsf(invasao.y);
					corpo.setPosition(posicao);
					//cout << "invasao vertical por cima" << endl;
					velocidade.y = 0.f;
					podePular = true;
				}
			}
		}

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
	vivo = true;
}

void Jogador::desenharOrbes()
{
	for (int i = 0; i < orbes.size(); i++) {
		orbes[i].atualizar();
		orbes[i].desenhar();
	}
}