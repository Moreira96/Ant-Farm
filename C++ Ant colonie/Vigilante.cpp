#include "RegraCome.h"

#include"Vigilante.h"
#include <iostream>
#include <sstream>
#include <string>

void Vigilante::adicionaRegra(Regras * x)
{
}

Vigilante::Vigilante(int n, const string & s, int c, int tea, int lin)
	:Formiga(n, s, c, tea, lin), coordX(n), coordY(c)
{
	nome = "vigilante";
	coordX = n;
	coordY = c;
	energia = 150;
	raiomovimento = 5;
	raiodevisao = 7;
	tipo = 'V';
//	Regras *x = new RegraFoge();
	Regras *z = new	RegraCome();
	//Regras *y = new RegraNinho();
	//adicionaRegra(new RegraFoge());
	//x->ligaFormigaRegra(this);
	z->ligaFormigaRegra(this);
//	y->ligaFormigaRegra(this);

	//adicionaRegra(x);
	adicionaRegra(z);
	//adicionaRegra(y);
}
int Vigilante::getrRAIODEVISAO() const
{
	return raiodevisao;
}

int Vigilante::getRAIOMOVIMENTO() const
{
	return raiomovimento;
}

int Vigilante::getENERGIA() const
{
	return energia;
}

char Vigilante::getTipo() const
{
	return tipo;
}

string Vigilante::getInfo()const
{
	ostringstream os;

	os << obtemInfo();

	return os.str();
}
