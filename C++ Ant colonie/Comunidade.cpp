
#include "Comunidade.h"
#include "Ninho.h"
#include "formiga.h"
#include "leituradecomandos.h"
#include "Iteraccao.h"

int Comunidade::conta = 1;

int Comunidade::getX() const
{
	return POSX;
}

int Comunidade::getY() const
{
	return POSY;
}



Comunidade::Comunidade(int q, int d)
	: POSX(q), POSY(d)
{	
}
Comunidade::~Comunidade()
{
	for (vector < Formiga*>::const_iterator it = fomigas.begin(); it != fomigas.end(); it++)
	{
		delete (*it);
		ninho = nullptr;
	}
	
}
int  Comunidade::getID() const 
{
	return id;
}

void  Comunidade::setID(int b)
{
	id = b;
}

Ninho * Comunidade::getNinho() const
{
	return ninho;
}

void Comunidade::adicionaformiga(Formiga *a)
{
	fomigas.push_back(a);
}

void Comunidade::adicionaNinho(Ninho * b)
{ 
	ninho = b;
}

vector<Formiga*> &Comunidade::getFormigas()
{
	return fomigas;
}

void Comunidade::mostraInfo() const
{

for( vector < Formiga*>::const_iterator it = fomigas.begin(); it != fomigas.end(); it++)
		{
			cout << (*it)->obtemInfo();
		}
}

string Comunidade::getInfo() const
{
	ostringstream os;
	os << "\n\t  Info Comunidade: " << endl;
	os << "\n  ID da Comunidade: \t" << id << "\n  N" << char(248) <<" de Formigas: \t" << fomigas.size() << endl;
	return os.str();
}