#include "stdafx.h"
#include "Jogador.h"
#include "Mago.h"

Jogador::Jogador(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, string caminhoCongelado) :
	Personagem(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(),
	lentidao(1),
	vivo(false),
	podePular(true),
	alturaPulo(150),
	tempoCongelamento(1.5),
	congelado(0),
	cooldownGelo(4),
	penalidadeAnte(1),
	penalidadeAtual(1),
	pontuacao(10000)
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
		limite += 0.3;
		morrer();
		aumentaPenalidade();
	}
	if (IdOutro == espinho) {
		morrer();
		aumentaPenalidade();
	}

	if (IdOutro == estalactite) {
		morrer();
		aumentaPenalidade();
	}

	if (IdOutro == golemPedra)
	{
		morrer();
		aumentaPenalidade();
	}
	if (IdOutro == golemFogo)
	{
		morrer();
		limite += 0.3;
		aumentaPenalidade();
	}
	if (IdOutro == golemGelo)
	{
		cooldownGelo = 3.f;
		morrer();
		aumentaPenalidade();
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

void Jogador::salvar()
{
	ofstream Gravador("salvar/Jogador.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << ' ' << hp << ' ' << podePular << ' ' << alturaPulo << ' ' << tempoCongelamento << ' ' <<
		congelado << ' ' << cooldownGelo << ' ' << penalidadeAnte << ' ' << penalidadeAtual << ' ' << pontuacao << endl;

	Gravador.close();

}

void Jogador::carregar(sf::Vector2f posicao, sf::Vector2f velocidade, sf::Vector2f dimensoes, bool viradoDir, bool podePular, bool congelado, int hp, int penalidadeAnte, int penalidadeAtual, float alturaPulo, float tempoCongelamento, float cooldownGelo, float pontuacao)
{
	this->posicao = posicao;
	this->velocidade = velocidade;
	this->dimensoes = dimensoes;
	this->viradoDir = viradoDir;
	this->podePular = podePular;
	this->alturaPulo = alturaPulo;
	this->tempoCongelamento = tempoCongelamento;
	this->congelado = congelado;
	this->cooldownGelo = cooldownGelo;
	this->penalidadeAnte = penalidadeAnte;
	this->penalidadeAtual = penalidadeAtual;
	this->pontuacao = pontuacao;
}



void Jogador::aumentaPenalidade()
{
	//A pontuacao do jogador comecara em 10,000 pontos, e irá receber penalidades a cada morte. A penalidade seguirá a sequencia de Fibonacci
	int aux = penalidadeAtual;
	penalidadeAtual += penalidadeAnte;
	penalidadeAnte = aux;
	pontuacao = pontuacao / penalidadeAtual;
}

float Jogador::getPontuacao()
{
	return pontuacao;
}

int Jogador::getPenalidadeAtual()
{
	return penalidadeAtual;
}

int Jogador::getPenalidadeAnte()
{
	return penalidadeAnte;
}
