#pragma once
class Mapa
{
private:
	sf::Vector2i mapa[30][30];
	sf::Vector2i contador = sf::Vector2i(0, 0);
	//int num_fase;

public:
	Mapa(const char* caminho = "");
	~Mapa();

	void carregarMapa(const char* caminho);
	int getInfoXMapa(int i, int j);
	int getInfoYMapa(int i, int j);
	sf::Vector2i getInfoMapa(int i, int j);
};
