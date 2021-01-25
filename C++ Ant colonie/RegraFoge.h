#pragma once

#include "Regras.h"

class Regras;

using  namespace std;

class RegraFoge : public Regras
{
	//string name;
	int conta;
public:
	RegraFoge();
	//RegraFoge();
//	string getNome()const;
	bool Regrasdefinida(Formiga*f, Comunidade * m);
	//bool RegraDefi(Formiga*f, Motor * m);
	void accao(Formiga * f, Formiga * x);
	Regras * duplicaa()
	{
		return new RegraFoge();
		//return new 
	}
};


