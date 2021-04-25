#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:

    //Atributos
    int hp;

public:

    //Construtora e Destrutora
    Personagem(sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL);
    ~Personagem();

    //Funcoes
    virtual void atualizar(float t) = 0;
    virtual void desenhar(sf::RenderWindow* j) = 0;
};

