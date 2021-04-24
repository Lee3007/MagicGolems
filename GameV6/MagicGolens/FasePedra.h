#pragma once
#include "Fase.h"

class FasePedra :
    public Fase
{
private:

public:
    FasePedra(int i = -1, const char* caminhoTile = "", const char* caminhoMapa = "");
    ~FasePedra();
    void setPosicaoJogadores();
    const sf::Vector2f getPontoFinal() const;
};

