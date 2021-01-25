#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Formiga;
class Motor;
class Comunidade;

class Regras
{
	string nome;
	Formiga *f;
	static int conta;
	Motor * m;
public:
	Regras(string n);
	virtual Regras* duplicaa() = 0;


//	string getNome() const;
	void ligaFormigaRegra(Formiga *x);
	/*bool Regrasdefinidas(Formiga*f, Formiga*fn);*/
	virtual bool Regrasdefinida(Formiga*f, Comunidade * m) =0;
	//virtual bool Regradef(Formiga *f, Motor* m) = 0;
	
};