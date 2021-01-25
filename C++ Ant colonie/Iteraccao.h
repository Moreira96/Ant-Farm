#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
class Motor;
class Formiga;
class Migalhas;
static const int MAXX = 100;
static const int MAXY = 100;

class Iteraccao {
	int lin = 10;
	int tempo = 10;
	char mapa[MAXX][MAXY];
	int cor[MAXX][MAXY];
	Motor *m;
	static int contatempo;
	bool joga = false;

public:
	Iteraccao(Motor *n);
	void criaMapa();
	void printConsola(int x, int y, char *m, int str, int yy);
	void criaConsola();
	void printMapa(int x, int y);
//	void getPos( Ninho *n, int x, int y);
	void getComando();
	void ImprimeFormigaTodas();
	void ImprimeNinhos();
	void contadordetempo();
	void ImprimeMigalhas();


	void moveTudo();
	void comandotempo(int x);
	~Iteraccao();
};