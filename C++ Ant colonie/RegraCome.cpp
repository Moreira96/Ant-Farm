#include "RegraCome.h"
//#include "RegraCome.h"
#include "Migalhas.h"

//#include "RegraFoge.h"
#include "Formiga.h"
#include "Comunidade.h"
#include "leituradecomandos.h"
#include <algorithm>
#include <math.h>

//
//RegraCome::RegraCome()
//	:Regras("regracome")
//{
//	cout << "FUI CRIADO";
//}
//
//bool RegraCome::Regrasdefinida(Formiga * f, Comunidade * m)
//{
//	{
////		vector<Migalhas *> todas = m->getFormigas();
//
//		Migalhas * ini = nullptr;
//
//		//for (Migalhas * x : todas) {
//
//		//		if (f->distancia(x->getX(), x->getY()) == true) {
//		//			ini = x;
//		//			do {
//
//		//				accao(f, x);
//		//			} while ((f->getX()> f->getLin() || f->getY())> f->getLin());
//		//		}
//
//		//	}
//			if (ini == nullptr) {
//
//				return false;
//			}
//		}
//	}
//
//
//void RegraCome::accao(Formiga * f, Migalhas * x)
//{
//}
//
//
//
//
//void RegraFoge::accao(Formiga *f, Migalhas *x)
//
//{
//	int xx = x->getX(), y = x->getCoordY();
//
//	f->setCoordX(xx);
//	f->setCoordY(y);
//	f->setEnergia(x->getEnergia());
//	x->comido();
//

RegraCome::RegraCome()
	:Regras("regracome")
{

}
bool ::RegraCome::Regrasdef(Formiga* f, Motor * m)
{
	{
		{
			vector<Migalhas *> todas = m->getMigalhas();
	
			Migalhas * ini = nullptr;
	
			for (Migalhas * x : todas) {
	
					if (f->distancia(x->getX(), x->getY()) == true) {
						ini = x;
						do {
	
							accao(f, x);
							if (f->getCoordX() == x->getX() && f->getCoordY() == x->getY())
							{
								x->comido();
							}
						} while ((f->getCoordX()> f->getLin() || f->getCoordY())> f->getLin());
					}
	
				}
				if (ini == nullptr) {
	
					return false;
				}
			}
		}
	
	

}
bool RegraCome::Regrasdefinida(Formiga * f, Comunidade * m)
{
	vector<Formiga*> todas = m->getFormigas();

	return false;
}

void RegraCome::accao(Formiga * f,	Migalhas * n)

{
		int xx = n->getX(), y = n->getY();
			
		f->setCoordX(xx);
		f->setCoordY(y);
		f->setEnergia(n->getEnergia());
		n->comido();
}
