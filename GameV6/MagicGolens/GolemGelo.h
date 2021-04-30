#pragma once
#include "Personagem.h"

class GolemGelo :
    public Personagem
{
private:

public:
    GolemGelo(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
    ~GolemGelo();
    void atualizar();
    void desenhar();
    void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro);
};

