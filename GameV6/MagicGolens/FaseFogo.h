#pragma once
#include "Fase.h"
class FaseFogo :
    public Fase
{
private:

public:
    FaseFogo(const char* caminhoTile = "", const char* caminhoMapa = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f));
    ~FaseFogo();

    void setPosicaoJogadores();
    const sf::Vector2f getPontoFinal() const;
    void criarInimigos();
};

