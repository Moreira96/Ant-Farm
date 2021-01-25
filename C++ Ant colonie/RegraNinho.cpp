#include "RegraNinho.h"
#include "Formiga.h"
#include "Comunidade.h"
#include "leituradecomandos.h"
#include <algorithm>
#include <math.h>
#include "Ninho.h"
RegraNinho::RegraNinho()
	:Regras("regraninho")
{
	
}

bool RegraNinho::Regrasdefinida(Formiga * f, Comunidade * m)
{
	int posantx = 0;
	int posanty = 0;
	unsigned totalx = 0;
	unsigned totaly = 0;

	Formiga *x = nullptr;
	Ninho * n = m->getNinho();

	if (f->distancia(n->getX(), n->getY()) == true)
	{
		x = f;
		cout << "friendly mate";
		do {
			posantx = n->getX();
			posanty = n->getY();
			accao(f, n);
			totalx = f->getCoordX() - posantx;
			totaly = f->getCoordY() - posanty;
			
				
		} while ((f->getCoordX() > f->getLin() || f->getCoordY()) > f->getLin());// || totalx > f->getRaiomovimento() || totaly > f->getRaiomovimento());
		
	}
	
	if (x == nullptr)
	{
		//cout << "ninho inimigo perto";

		return false;
	}
}


void RegraNinho::accao(Formiga * f,Ninho * n)
{
	
	int num = 0; 
	int max = 0; 
	for (int i = f->getCoordX() - (f->getRaiomovimento()); i < f->getCoordX() + f->getRaiomovimento(); i++) {
		for (int j = (f->getCoordX() - (f->getRaiomovimento())); j < f->getCoordY() + f->getRaiomovimento(); j++)
		{
			num = f->distanciafoge(n->getX(), n->getY());
				if (num <= f->getRaiomovimento() && num > max)
				{
					max = num; 
				
				}
		}
	}
}


