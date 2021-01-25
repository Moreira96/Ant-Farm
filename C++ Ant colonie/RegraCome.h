#include "Regras.h"

class Regras;
class Formiga;
class Comunidade;
class Ninho;
class Migalhas;

using  namespace std;

class RegraCome : public Regras
{
	//string name;
	int conta;

public:
	RegraCome();
	//RegraFoge();
	//	string getNome()const;
	bool Regrasdefinida(Formiga*f, Comunidade * m);
	bool Regrasdef(Formiga *f, Motor *m);
	void accao(Formiga * f, Migalhas *n);

	Regras * duplicaa()
	{
		return new RegraCome();
		//return new 
	}
};


