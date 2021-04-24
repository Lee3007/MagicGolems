#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:

public:

    //Construtora e Destrutora
    Jogador(sf::Vector2f tam = sf::Vector2f(20.f, 40.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL);
    ~Jogador();

    //Funcoes
    void atualizar(float t);
    void desenhar(sf::RenderWindow *j);
    void setPosicao(sf::Vector2f p);
    sf::Vector2f getPosicao();
};

