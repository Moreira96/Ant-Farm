#pragma once
#include "formiga.h"

using namespace std;
class Regras;

class Cuidadora :public Formiga
{
	char tipo;
	int energia;
	int coordX;
	int coordY;
	int raiomovimento;
	int raiodevisao;
	string nome;
	
	void adicionaRegra(Regras*x);
public:
	Cuidadora(int n, const string &s, int c, int tea, int lin);
	int getENERGIA()const;
	char getTipo() const;
	int getrRAIODEVISAO() const;
	int getRAIOMOVIMENTO() const;
	string getInfo()const;
	Formiga * duplica() {
		return new Cuidadora(*this);
	}
	
};