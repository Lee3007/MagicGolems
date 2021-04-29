#pragma once
#include "Personagem.h"

class GolemFogo :
    public Personagem
{
private:

public:
    GolemFogo(sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
    ~GolemFogo();
    void atualizar();
    void desenhar();
};

