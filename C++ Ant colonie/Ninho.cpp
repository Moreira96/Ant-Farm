#include "Ninho.h"
#include "formiga.h"
#include "Iteraccao.h"
#include "leituradecomandos.h"

using namespace std;


int Ninho::conta = 1;

Ninho::Ninho(int xx, int yy, int energia)
	:x(xx), y(yy), id(conta)
{
	energ = energia;
	conta++;
}

string  Ninho::getAsString() const
{
	ostringstream oss;
	oss << "\nNinho: \nx = " << x << "\n y = " << y << "\n Energia = " << energ << "\n ID = " << id << endl;
	return oss.str();
}

void Ninho::adicionaFormiga( Formiga *f)
{
	formig.push_back(f);
}
int Ninho::getID() const
{
	return id;
}

void  Ninho::mostraInfoNinho() const 
{
	ostringstream ss;

	for (unsigned int i = 0; i < formig.size(); i++)
	{
		cout << formig[i]->obtemInfo();	
	}
}
int Ninho::getId() const
{
	return id; 
}

int Ninho::getX() const
{
	return x;
}
int Ninho::getY() const
{
	return y; 
}

int Ninho::getEnergiaNinho() const
{
	return energ; 
}
char Ninho::getTipo() const
{
	return tipo;
}
Ninho::~Ninho()
{
	for (vector<Formiga*>::const_iterator it = formig.begin();
		it != formig.end(); it++)
	{
		delete (*it);
		
	}
}

vector<Formiga*> Ninho::getInfoFormigas() {

	for (vector <Formiga*>::const_iterator ita = formig.begin(); ita != formig.end(); ita++)
	{
		cout << (*ita)->obtemInfo();
	}
	return formig;
}
