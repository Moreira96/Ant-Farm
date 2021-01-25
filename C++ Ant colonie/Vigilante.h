#pragma once
#include "formiga.h"

using namespace std;


class Vigilante :public Formiga
{
	char tipo;
	int energia;
	int coordX;
	int coordY;
	int raiomovimento;
	int raiodevisao;
	string nome;
	void adicionaRegra(Regras *x);

public:
	Vigilante(int n, const string &s, int c, int tea, int lin);
	int getENERGIA()const;
	char getTipo() const;
	int getrRAIODEVISAO() const;
	int getRAIOMOVIMENTO() const;

	string getInfo()const;
	Formiga * duplica() {
		return new Vigilante(*this);
	}
	//void adicionaRegra(Regras*x);

};