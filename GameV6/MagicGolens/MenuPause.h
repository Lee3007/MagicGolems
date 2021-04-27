#pragma once
#include "Menu.h"
#include "stdafx.h"

class GerenciadorEstado;
class GerenciadorGrafico;
class MenuInicial;

class MenuPause :
    public Menu
{
private:

    sf::Text opcoes[2];
    MenuInicial* MenuIni;
    
public:
    MenuPause(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground = "");
    ~MenuPause();
    void inicializarMenu();
    void moverCima();
    void moverBaixo();
    void desenhar(sf::RenderWindow* j);
    void executarEnter();
    void setMenuInicial(MenuInicial* m);
};

