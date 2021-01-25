
#include"RegraNinho.h"
#include "RegraFoge.h"
#include "RegraCome.h"
#include"Cuidadora.h"
#include <iostream>
#include <sstream>
#include <string>

void Cuidadora::adicionaRegra(Regras * x)
{
//	vector <Regras*> temp;
	
//	cout << "temp1size  : " << temp.size();
	preencheRegras(x);
//	cout << "temp2size  : " << temp.size();
	//system("pause");
}

Cuidadora::Cuidadora(int n, const string & s, int c, int tea, int lin)
	:Formiga(n, s, c, tea, lin), coordX(n), coordY(c)
{
	nome = "cuidadora";
	coordX = n;
	coordY = c;
	energia = 100;
	raiomovimento = 3;
	raiodevisao = 5;
	tipo = 'C';
	Regras *x = new RegraFoge();
	Regras *z = new	RegraCome();
	Regras *y = new RegraNinho();
	//adicionaRegra(new RegraFoge());
	x->ligaFormigaRegra(this);
	z->ligaFormigaRegra(this);
	y->ligaFormigaRegra(this);
	
	adicionaRegra(x);
	adicionaRegra(z);
	adicionaRegra(y);
}

int Cuidadora::getENERGIA() const
{
	return energia;
}

char Cuidadora::getTipo() const
{
	return tipo;
}
int Cuidadora::getrRAIODEVISAO() const
{
	return raiodevisao;
}

int Cuidadora::getRAIOMOVIMENTO() const
{
	return raiomovimento;
}
string Cuidadora::getInfo()const
{
	ostringstream os;

	os << obtemInfo();

	return os.str();
}

//void Cuidadora::adicionaRegra(Regra *x)
//{
//	
//}