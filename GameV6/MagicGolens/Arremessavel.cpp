#include "stdafx.h"
#include "Arremessavel.h"

Arremessavel::Arremessavel(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, ListaEntidades* lista, GerenciadorColisoes* Gc) :
	Entidade(ID, tam, p, v, caminhoTextura, t, j),
	LEntidades(lista),
	GColisoes(Gc)
{
	if (lista == NULL || Gc == NULL)
	{
		exit(891);
	}
}

Arremessavel::~Arremessavel()
{
}

void Arremessavel::desenhar()
{
	janela->draw(corpo);
}

void Arremessavel::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
	if (IdOutro != naocolidivel && IdOutro != jogador && IdOutro != porta)
	{
		LEntidades->removerDestruir(this);
	}
	
}