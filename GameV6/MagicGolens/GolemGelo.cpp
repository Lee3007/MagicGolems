#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, float tamCristal) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(3),
	tamanhoCristal(tamCristal)
{
	if (Id == boss)
		hp = 1000;
}

void GolemGelo::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (podeAtirar)
	{
		arremessarCristal();
		cooldown = 0.f;
		podeAtirar = false;
	}

	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}

void GolemGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == jogador)
	{
		if (nivel <= 5)
		{
			limite -= 0.4;
			nivel++;
			if (Id != boss)
				tamanhoCristal += 0.2;
		}
	}

	if (IdOutro == orb)
	{
		hp -= 100;
		if (hp <= 0)
			destruir = true;
	}
}

void GolemGelo::arremessarCristal()
{
	CristalGelo* pCristal = NULL;

	if (Id != boss) {
		if (viradoDir)
			pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(300.f, -300.f), "text/cristal.png", dt, janela);
		else
			pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(-300.f, -300.f), "text/cristal.png", dt, janela);
	}
	else {
		float velx;
		float vely;
		vely = -300 - static_cast<float>(rand() % 150);
		velx = -300 - static_cast<float>(rand() % 300);
		pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(velx, vely), "text/cristal.png", dt, janela);
	}

	LEntidades->incluirEntidade(pCristal);
	GColisoes->adicionarEntidade(pCristal);
}

void GolemGelo::salvar() {
	ofstream Gravador("salvar/GolemGelo.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << ' ' << hp << ' ' << nivel << ' ' << limite << ' ' << cooldown << ' ' << podeAtirar << endl;

	Gravador.close();
}

