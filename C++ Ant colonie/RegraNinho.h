#pragma once


#include "Regras.h"

class Regras;
class Formiga;
class Comunidade;
class Ninho; 
using  namespace std;

class RegraNinho : public Regras
{
	//string name;
	int conta;

public:
	RegraNinho();
	//RegraFoge();
	//	string getNome()const;
	bool Regrasdefinida(Formiga*f, Comunidade * m);
	//bool Regrasdef(Formiga *f, Motor *m);
	void accao(Formiga * f, Ninho *n);
	Regras * duplicaa()
	{
		return new RegraNinho();
		//return new 
	}
};


