#pragma once

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Migalhas {
	int energia;
	int x;
	int y;
	char tipo = 'M';

public:

	Migalhas(int energ, int xx, int yy);	//Energia Configurável

	void perdeEnergia();	//perde Energia por cada Iteracão

	int getEnergia()const;
	int getX()const;
	int getY()const;

	void comido();

	~Migalhas() {};
};