#pragma once
#include "Personagem.h"
class GolemPedra :
    public Personagem
{
private:

public:
    GolemPedra(sf::Vector2f tam = sf::Vector2f(20.f, 40.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
    ~GolemPedra();
    void atualizar();
    void desenhar();
};
