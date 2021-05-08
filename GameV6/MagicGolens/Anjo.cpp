#include "stdafx.h"
#include "Anjo.h"

Anjo::Anjo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, string caminhoCongelado) :
	Jogador(ID, tam, p, v, caminhoTextura, t, j, caminhoCongelado)
{
}

Anjo::~Anjo()
{
}

void Anjo::atualizar()
{
	cooldown += *dt;
	possoAtirar(cooldown);

	cooldownGelo += *dt;
	descongelado(cooldownGelo);

	if (!congelado) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
		{
			salvar();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		{
			carregar();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			velocidade.x = 600.f / lentidao;
			corpo.setScale(sf::Vector2f(1.f, 1.f));
			viradoDir = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			velocidade.x = -600.f / lentidao;
			corpo.setScale(sf::Vector2f(-1.f, 1.f));
			viradoDir = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && podePular)
		{
			podePular = false;
			velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && podeAtirar) {
			podeAtirar = false;
			Orbe* pOrbe = NULL;

			if (viradoDir)
				pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(800.f, 0.f), "text/orbe.png", dt, janela);
			else
				pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(-800.f, 0.f), "text/orbe.png", dt, janela);

			GColisoes->adicionarEntidade(pOrbe);
			LEntidades->incluirEntidade(pOrbe);

			cooldown = 0.f;
		}
		velocidade.x *= 0.9f;
	}
	velocidade.y += 98.1f;


	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void Anjo::salvar() {
	ofstream Gravador("salvar/Anjo.txt", ios::trunc);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << ' ' << hp << ' ' << podePular << ' ' << alturaPulo << ' ' << tempoCongelamento << ' ' <<
		congelado << ' ' << cooldownGelo;

	Gravador.close();
}

void Anjo::carregar() {
	ifstream Carregador("salvar/Anjo.txt", ios::in);

	if (!Carregador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(67);
	}

	Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> dimensoes.x >>
		dimensoes.y >> viradoDir >> hp >> podePular >> alturaPulo >> tempoCongelamento >>
		congelado >> cooldownGelo;

	Carregador.close();
}