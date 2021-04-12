#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:

public:

    //Construtora e Destrutora
    Jogador(sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f));
    ~Jogador();

    //Funcoes
    void atualizar(float t);
    void desenhar(sf::RenderWindow *j);
};

