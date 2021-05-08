#include "stdafx.h"
#include "Mago.h"

Mago::Mago(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, string caminhoCongelado) :
	Jogador(ID, tam, p, v, caminhoTextura, t, j, caminhoCongelado),
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

	cooldownGelo += *dt;
	descongelado(cooldownGelo);

	if (!congelado) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			this->salvar();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
		{
			this->carregar();
		}
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

void Mago::salvar() {
	ofstream Gravador("salvar/Mago.txt", ios::trunc);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << ' ' << hp << ' ' << podePular << ' ' << alturaPulo << ' ' << tempoCongelamento << ' ' <<
		congelado << ' ' << cooldownGelo << ' ' << penalidadeAnte << ' ' << penalidadeAtual << ' ' << pontuacao;

	Gravador.close();
}

void Mago::carregar() {
	ifstream Carregador("salvar/Mago.txt", ios::in);

	if (!Carregador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(67);
	}

	Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> dimensoes.x >>
		dimensoes.y >> viradoDir >> hp >> podePular >> alturaPulo >> tempoCongelamento >>
		congelado >> cooldownGelo >> penalidadeAnte >> penalidadeAtual >> pontuacao;

	Carregador.close();
}