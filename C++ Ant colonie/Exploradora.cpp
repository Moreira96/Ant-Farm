#include "RegraCome.h"
#include"Exploradora.h"
#include <iostream>
#include <sstream>
#include <string>


void Exploradora::adicionaRegra(Regras * x)
{
}

Exploradora::Exploradora(int n, const string & s, int c, int tea, int lin)
	:Formiga(n, s, c, tea, lin), coordX(n), coordY(c)
{
	nome = "exploradora";

	//coordX = n;
	//coordY = c;
	energia = 150;
	raiomovimento = 5;
	raiodevisao = 7;
	tipo = 'E';
//	Regras *x = new RegraFoge();
	Regras *z = new	RegraCome();
//	Regras *y = new RegraNinho();
	//adicionaRegra(new RegraFoge());
//	x->ligaFormigaRegra(this);
	z->ligaFormigaRegra(this);
//	y->ligaFormigaRegra(this);

//	adicionaRegra(x);
	adicionaRegra(z);
//	adicionaRegra(y);
}

int Exploradora::getENERGIA() const
{
	return energia;
}

char Exploradora::getTipo() const
{
	return tipo;
}

string Exploradora::getInfo()const
{
	ostringstream os;

	os << obtemInfo();

	return os.str();
}
int Exploradora::getrRAIODEVISAO() const
{
	return raiodevisao;
}

int Exploradora::getRAIOMOVIMENTO() const
{
	return raiomovimento;
}
