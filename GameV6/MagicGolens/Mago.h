#pragma once
#include "Jogador.h"
class Mago :
    public Jogador
{
private:

public:

    Mago(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(60.f, 90.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, string caminhoCongelado = NULL);
    ~Mago();
    void atualizar();
};

