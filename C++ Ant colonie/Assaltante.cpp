#include "RegraCome.h"
#include "RegraPersegue.h"
#include"Assaltante.h"
#include <iostream>
#include <sstream>
#include <string>


void Assaltante::adicionaRegra(Regras * x)
{
}

Assaltante::Assaltante(int n, const string & s, int c, int tea, int lin)
	:Formiga(n, s, c, tea, lin), coordX(n), coordY(c)
{
	nome = "assaltante";
	coordX = n;
	coordY = c;
	energia = 80;
	raiomovimento = 4;
	raiodevisao = 8;
	tipo = 'A';
//	Regras *x = new RegraFoge();
	Regras *z = new	RegraCome();
	Regras *x = new RegraPersegue();
//	Regras *y = new RegraNinho();
	//adicionaRegra(new RegraFoge());
//	x->ligaFormigaRegra(this);
	z->ligaFormigaRegra(this);
//	y->ligaFormigaRegra(this);

	adicionaRegra(x);
	adicionaRegra(z);
	//adicionaRegra(y);

}

int Assaltante::getENERGIA() const
{
	return energia;
}

char Assaltante::getTipo() const
{
	return tipo;
}

int Assaltante::getrRAIODEVISAO() const
{
	return raiodevisao;
}

int Assaltante::getRAIOMOVIMENTO() const
{
	return raiomovimento;
}

string Assaltante::getInfo()const
{
	ostringstream os;

	os << obtemInfo();

	return os.str();
}
