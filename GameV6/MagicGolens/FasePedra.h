#pragma once
#include "Fase.h"

class FasePedra :
    public Fase
{
private:

public:
    FasePedra(const char* caminhoTile = "", const char* caminhoMapa = "");
    ~FasePedra();
    void setPosicaoJogadores();
    const sf::Vector2f getPontoFinal() const;
};

