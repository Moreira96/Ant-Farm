#include "RegraPersegue.h"
#include "Formiga.h"
#include "Comunidade.h"
#include "leituradecomandos.h"
#include <algorithm>
#include <math.h>


RegraPersegue::RegraPersegue()
	:Regras("regrafoge")
{
	cout << "FUI CRIADO";
}



//
//string RegraFoge::getNome()const
//{
//	return	name;
//}

bool RegraPersegue::Regrasdefinida(Formiga * f, Comunidade * m)
{
	int posantx = 0;
	int posanty = 0;
	unsigned totalx = 0;
	unsigned totaly = 0;
	cout << "teste 1";
	{
		vector<Formiga *> todas = m->getFormigas();

		Formiga * ini = nullptr;
		//cout << "teste 2";
		for (Formiga * x : todas) {
			//cout << "teste 3";
			//cout <<"x " <<x->getComunidade();
			//cout << " f " << f->getComunidade();
			if (f->getComunidade() != x->getComunidade()) {
				//cout << " sadsadasd";
			if (f->distancia(x->getCoordX(), x->getCoordY()) == true) {
					ini = x;
					do {
						f->setCoordX(x->getCoordX());
						f->setCoordY(x->getCoordY());
					//	cout << "arranquei";
						//	cout << "1 " << totalx << "2 " << totaly;
					} while ((f->getCoordX() > f->getLin() || f->getCoordY()) > f->getLin());// || totalx > f->getRaiomovimento() || totaly > f->getRaiomovimento());
				}

			}
			if (ini == nullptr) {

				return false;
			}
		}
	}
}


void RegraPersegue::accao(Formiga *f, Formiga *x)

{
	int max = 0;
	int num = 0;
	int xx = f->getCoordX(), y = f->getCoordY();


	for (int i = f->getCoordX() - (f->getRaiomovimento()); i < f->getCoordX() + f->getRaiomovimento(); i++)
		for (int j = (f->getCoordX() - (f->getRaiomovimento())); j < f->getCoordY() + f->getRaiomovimento(); j++)
		{
			//	cout << "enciclo";
			num = f->distanciafoge(x->getCoordX() + i, x->getCoordY() + j);
			//	cout << "NUM |" << num << "|" << "RAIO |" << f->getRaiomovimento()<< endl;
			if (num <= f->getRaiomovimento())

				if (num > max)
				{

					
					max = num;

				}

		}

	
}


