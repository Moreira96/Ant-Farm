#include "formiga.h"
#include "Regras.h"
#include "RegraFoge.h"
#include <algorithm>
#include "Comunidade.h"

int  Regras::conta = 0;
Regras::Regras(string n)
{
//	conta++;
	//nome = n; 
	if (n.compare( "regrafoge")==0)
	{
		nome = n; 
		//RegraFoge *b = new RegraFoge();
	
		cout << conta;
	}
	if (n.compare("regraninho") == 0)
	{
		nome = n;
		//conta++;
	//	cout << conta;
	}
	if (n.compare("regracome") == 0)
	{
		nome = n;
	}

}
//string Regras::getNome() const
//{
//	return nome;
//}

void Regras::ligaFormigaRegra(Formiga * x)
{
	f = x; 
}

//bool Regras::Regrasdefinidas(Formiga * f, Motor * m)
//{
////	int i = 0;
//	//if (nome.compare("regrafoge"))
//	{
//		Comunidade  *c = f->getComunidade();
//		Comunidade *d = fn->getComunidade();
//
//	//	system("Pause");
//		for (vector<Formiga*>::const_iterator it = c->getFormigas().begin(); it != c->getFormigas().end(); it++)
//		{
//			for (vector<Formiga*>::const_iterator ita = d->getFormigas().begin(); ita != d->getFormigas().end(); ita++)
//			{
//				cout << *it << " " << *ita << endl;
//				cout << max(abs((*it)->getCoordX() - (*ita)->getCoordX()), abs((*it)->getCoordY() - (*ita)->getCoordY())) << (*it)->getCoordY() << (*ita)->getCoordY();
//					if ((max(abs((*it)->getCoordX() - (*ita)->getCoordX()), abs((*it)->getCoordY() - (*ita)->getCoordY())) <= (*it)->getRaiodeVisao()))// /*&& */((*it)->getID() != (*ita)->getID()))
//					{
//
//
//						//		system("pause");
//								//(*it)->setCoordX((*it)->getCoordX());
//								//(*it)->setCoordY((*it)->getCoordY());
//								//cout << "estou a fugir";
//								//i = 1;
//						cout << "estao perto!";
//						return false;
//
//
//
//					}
//					else
//					{
//
//						return true;
//						cout << "estao longe ";
//					}
//				
//
//				
//			}
//		}
//	}
//	
//	return false;
//	
//
//}


