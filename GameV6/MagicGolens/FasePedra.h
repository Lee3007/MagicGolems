#pragma once
#include "Fase.h"

class FasePedra :
    public Fase
{
private:

public:
    FasePedra(const char* caminhoTile = "", const char* caminhoMapa = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f));
    ~FasePedra();
    void setPosicaoJogadores();
    const sf::Vector2f getPontoFinal() const;
    void criarInimigos();
};

