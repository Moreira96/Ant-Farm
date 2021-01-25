#pragma once

#include "Regras.h"

class Regras;

using  namespace std;

class RegraPersegue : public Regras
{
	//string name;
	int conta;
public:
	RegraPersegue();
	//RegraFoge();
	//	string getNome()const;
	bool Regrasdefinida(Formiga*f, Comunidade * m);
	//bool RegraDefi(Formiga*f, Motor * m);
	void accao(Formiga * f, Formiga * x);
	Regras * duplicaa()
	{
		return new RegraPersegue();
		//return new 
	}
};


