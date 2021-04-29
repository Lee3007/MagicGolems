#pragma once
#include "stdafx.h"
#include "Menu.h"

class MenuInicial;

class MenuFases :
    public Menu
{
private:
    sf::Text opcoes[4];
    MenuInicial* MenuIni;

public:
    MenuFases(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
    ~MenuFases();
    void inicializarMenu();
    void desenhar();
    void moverCima();
    void moverBaixo();
    void executarEnter();
    void setMenuInicial(MenuInicial* m);

};

