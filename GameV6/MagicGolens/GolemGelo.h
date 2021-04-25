#pragma once
#include "Personagem.h"

class GolemGelo :
    public Personagem
{
private:

public:
    GolemGelo(sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL);
    ~GolemGelo();
    void atualizar(float t);
    void desenhar(sf::RenderWindow* j);
};

