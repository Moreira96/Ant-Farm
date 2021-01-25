#include "Migalhas.h"

Migalhas::Migalhas(int energ, int xx, int yy)
{
	//Não pode haver duas migalhas na mesma posição (Receber posição a partir do Motor???)
	x = xx;
	y = yy;

	energia = energ;
}

void Migalhas::perdeEnergia()
{
	energia -= 1;
}

int Migalhas::getEnergia() const
{
	return energia;
}

int Migalhas::getX()const 
{
	return x;
}

int Migalhas::getY()const 
{
	return y;
}

void Migalhas::comido()
{
	energia = 0;
}
