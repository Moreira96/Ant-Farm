#include "leituradecomandos.h"
#include "Iteraccao.h"
#include "Consola.h"
#include "formiga.h"
#include "Ninho.h"
#include "Comunidade.h"
#include "Exploradora.h"
#include "Assaltante.h"
#include "Cuidadora.h"
#include "Vigilante.h"
#include <algorithm>
#include <math.h>
#include "RegraFoge.h"
#include "Regras.h"
#include "Migalhas.h"
Motor::Motor()
{

}
vector<string> Motor::lercomando(string pal, bool *cmd, bool *joga)
{
	*cmd = adiciona(pal, &(*joga));
	return comandos;	
}

int Motor::conta(string s)
{
	int conta = 0;
	istringstream is;
	is.str(s);
	
	while (is >> s)
	{
		conta++;
	}
	return conta; 
}

Ninho  Motor::criaNinho(int l,int c)
{
    	Ninho *n 	= new Ninho(l, c, 40);

		//ninhos.push_back(n);
		Comunidade *a = new Comunidade(l,c);
		a->setID(n->getID());
		a->adicionaNinho(n);
		
		comun.push_back(a);

	return *n;

}

Motor::~Motor()
{
	cout << "A encerrar programa !!";
}

vector<Migalhas*> Motor::getMigalhas()
{

	return mig;
}

vector<Migalhas*> Motor::getMigalhasImp()
{
	return mig;
}

void Motor::adicionaMigalhas(int num)
{
	int x = rand() % lin + 1;
	int y = rand() % lin + 1;
	bool m = false;

	for (int i = 0; i < num; i++)
	{
		if (mig.size() > 0) {
			while (m == false) {
				x = rand() % lin + 1;
				y = rand() % lin + 1;
				m = true;

				for (vector <Migalhas*>::const_iterator ita = mig.begin(); ita != mig.end(); ita++)
				{
					if (x == (*ita)->getX() && y == (*ita)->getY())
					{
						m = false;
					}
				}
			}
		}

		Migalhas *a = new Migalhas(10, x, y);
		mig.push_back(a);
		m = false;
	}
}
void  Motor::criaFormiga(int n,string o, int e)
{
	int conta= 0;
	int l,c;

	for (int i = 0; i < n; i++)
	{
		for (vector <Comunidade*>::const_iterator ita = comun.begin(); ita != comun.end(); ita++)
		{
			
			{
				if (((*ita)->getNinho()->getId()) == e && ((*ita)->getID() == e))
				{
					l = (*ita)->getNinho()->getX();
					c = (*ita)->getNinho()->getY()+i+1;
					
					if (o.compare("c") == 0)
					{
						Cuidadora *b = new Cuidadora(l, o, c, e, lin);
						
						b->setEnergia(b->getENERGIA());
						b->setEnergiaInicial(b->getEnergia());
						b->setTipo(b->getTipo());
						b->setRaiodeVisao(b->getrRAIODEVISAO());
						b->setRaiodeMovimento(b->getRAIOMOVIMENTO());
				//		ants.push_back(b);
					//	cout << "NOME DA BASE " << c->getNOME();
						//c->ligaFormigaRegra(b);
					//	b->adicionaRegra(c);
						
						linka(b, (*ita)->getNinho(), (*ita));
					}
					else
						if (o.compare("v") == 0)
						{
			
							Vigilante *b = new Vigilante(l, o, c, e, lin);
							b->setEnergia(b->getENERGIA());
							b->setEnergiaInicial(b->getEnergia());
							b->setTipo(b->getTipo());
							b->setRaiodeVisao(b->getrRAIODEVISAO());
							b->setRaiodeMovimento(b->getRAIOMOVIMENTO());
						//	b->setRaiodeVisao(b->getRAIODEB) 
						//	ants.push_back(b);
							linka(b, (*ita)->getNinho(), (*ita));
						}
						else
							if (o.compare("a") == 0)
							{
									Assaltante *b = new Assaltante(l, o, c, e, lin);
								b->setEnergia(b->getENERGIA());
								b->setTipo(b->getTipo());
								b->setEnergiaInicial(b->getEnergia());
								b->setTipo(b->getTipo());
								b->setRaiodeVisao(b->getrRAIODEVISAO());
								b->setRaiodeMovimento(b->getRAIOMOVIMENTO());

								//			ants.push_back(b);
								linka(b, (*ita)->getNinho(), (*ita));
							}
							else
								if (o.compare("e") == 0)
								{
									Exploradora *b = new Exploradora(l, o, c, e, lin);
									b->setEnergia(b->getENERGIA());
									b->setTipo(b->getTipo());
								//	cout << b->getTipo();
									b->setEnergiaInicial(b->getEnergia());
									b->setTipo(b->getTipo());
									b->setRaiodeVisao(b->getrRAIODEVISAO());
									b->setRaiodeMovimento(b->getRAIOMOVIMENTO());
							//	cout <<	b->getRaiomovimento();

									//			ants.push_back(b);
									linka(b, (*ita)->getNinho(), (*ita));
								}
					
								
								else
									if (o.compare("s") == 0)

									{
									}

					//Formiga *b = new Formiga(l, o, c, e, lin);//l = Largura , o = 
					//(*ita)->adicionaformiga(b);
					
				}
			}
		}
	}
}

bool Motor::adiciona(string s, bool *joga)
{
	istringstream is;
	is.str(s);
	comandos.clear();
	int count;
	int linha, coluna,num,id;
	string pal2;
	string teste;
	count = conta(s);

	if (count == 1)
	{
		while (is >> s)
		{
			if (s.compare("tempo") == 0)
			{
				comandos.push_back(s);
				tempo = 1;
				return true;
			}
				else
					if (s.compare("listamundo") == 0)
					{
						comandos.push_back(s);
						getMundo();
						return true;
					}
						else
							if (s.compare("listaposicao") == 0)
							{
								comandos.push_back(s);
								return true;
							}
							else
								if (s.compare("mostra") == 0)
								{
									comandos.push_back(s);
									getFormigas();
									return true;
						
								}
								else
									if (s.compare("joga") == 0)
									{
										*joga = true;
										return true;
									}
									else
										if (s.compare("sair") == 0)
										{
											return NULL;
										}
										else
										{
											return false;
										}
		}

	}
	else
	if (count == 2)
	{
		teste = s; 
		
		while (is >> s >> pal2)
		{
				if ((s.compare("executa") == 0))
					{
						lerdoFicheiro(pal2);
						comandos.push_back(teste);
						return true;
					}
				else
				if ((s.compare("listaninho")) == 0)
				{
							
					num = stoi(pal2);
					comandos.push_back(teste);
					getComunidade(num);
					return true;
				}
				else
					if ((s.compare("tempo")) == 0)
					{
						
						
							tempo = stoi( pal2);
							return true;
					}else
						if ((s.compare("defmundo")) == 0)
						{
							lin = stoi(pal2);
							return true;
						}
						else
							if ((s.compare("defnm")) == 0)
							{
								pmig = stoi(pal2);
								return true;
							}
							else
								if ((s.compare("defmi")) == 0)
								{
									adicionaMigalhas((stoi(pal2) / 100)*lin * lin);
									return true;
								}
				return false;
				}
		}

	if (count == 3)
	{
		while (is >> s >> linha >> coluna)
		{
		if (s.compare("ninho") == 0)
		{
			criaNinho(linha, coluna);
			return true;
		}
		else
			return false;
		}
	}
	if (count == 4)
	{
		while (is >> s >> num >> pal2 >> id)
		{
			if (s.compare("criaf") == 0)
			{
				criaFormiga(num, pal2, id);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
	cout << endl;
}

bool Motor::lerdoFicheiro(string pal)
{
	bool cmdd = false;
	bool joga;
	ifstream fich(pal);

	string comando;
	int count = 0;
	if (!fich.is_open())
	{
		return false;
	}
	while (!fich.eof())
	{

		getline(fich, comando);
		//	mostracomando();

		lercomando(comando, &cmdd, &joga);
		if (cmdd == false)
		{
			cout << "erro";
		}
		cout << endl;
	}
	fich.close();
	comandos.clear();
	return true;
}

void Motor::mostracomando()
{
	for (unsigned int i = 0; i < comandos.size(); i++)
	{
		cout << endl << "\nEntrou :" << comandos[i] << endl;
	}
}

Comunidade & Motor::linka(Formiga *b, Ninho *a, Comunidade *c)
{
	//c->adicionaNinho(a);
	c->adicionaformiga(b);

	a->adicionaFormiga(b);

	b->adicionaComunidade(c);
	b->adicionaNinho(a);

	return *c;
}

vector<Formiga*> Motor::getFormigas()
{
	vector<Formiga*>temp;
	temp.clear();
	for (vector <Comunidade*>::const_iterator it = comun.begin(); it != comun.end(); it++)
	{
		for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end(); ita++)
		{
			cout << (*it)->getInfo();
			(*it)->mostraInfo();
			temp.push_back((*ita));

		}
	}
	return temp;
}
vector<Formiga *> Motor::getFormigasImpTodas()
{
	vector<Formiga*>temp;
	temp.clear();
	for (vector <Comunidade*>::const_iterator it = comun.begin(); it != comun.end(); it++)
	{
		for(vector<Formiga*>::const_iterator ita= (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end();ita++)
		temp.push_back((*ita));
	}

	return temp;
}
vector <Comunidade*> Motor::getNinhoImprime()
{
	return comun;
}

void Motor::mover()
{
	int i = 0;
	int j = 0;
	int x=0, y=0, r;
	bool f = false;
	
	if (pmig > 0)
		adicionaMigalhas(rand() % pmig + 1);
	for (vector <Migalhas*>::const_iterator it = mig.begin(); it != mig.end();)
	{
		(*it)->perdeEnergia();
		if ((*it)->getEnergia() <= 0) {
			delete (*it);
			it = mig.erase(it);
		}
		else
			it++;

	}
	//cout << "cheguei";
	for (vector <Comunidade*>::const_iterator it = comun.begin(); it != comun.end();it++)
	{
		for(vector<Comunidade*>::const_iterator itf = comun.begin()+1;itf!=comun.end();itf++)


		for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end(); ita++) {
			//cout << "cheguei3";
			
			do
			{
				
//				movimento();


								//x = (max(abs((*ita)->getCoordX() - i), abs((*ita)->getCoordY() - j)));
								//movimento();
								//y = (max(abs((*ita)->getCoordY() - i), abs((*ita)->getCoordX() - j)));// abs((*ita)->getCoordX() - j);
								//	movimento();
							//	cout << "fds " << x << endl << y;
										r = rand() % 4;
										x = 0;
										y = 0;
										if (r == 0)
											x--;
										if (r == 1)
											y--;
										if (r == 2)
											x++;
										if (r == 3)
											y++;

									//	cout << (*ita)->getRegras().size();
										
			for (vector<Formiga*>::const_iterator ite = (*itf)->getFormigas().begin(); ite != (*itf)->getFormigas().end(); ite++)
			{
		
				for (vector<Regras*>::const_iterator itc = (*ita)->getRegras().begin(); itc != (*ita)->getRegras().end(); itc++)
				{
				//	cout << "Aqui!!!->" << (*ite)->getRegras().size();
					if(itc == (*ita)->getRegras().begin())
					f = (*itc)->Regrasdefinida((*ita), (*ite)->getComunidade());
				

					if ((itc) == (*ita)->getRegras().begin() + 1)
							f = (*itc)->Regrasdefinida((*ita), (*ita)->getComunidade());
						
				}

				if ((((*ita)->getCoordX()) == ((*ite)->getCoordX())) && (((*ita)->getCoordY()) == ((*ite)->getCoordY())))
				{
					(*ita)->setId(9);

					f = false;
				}
			
				
			}

			if ((*ita)->getCoordX() + x <= 0 || (*ita)->getCoordX() + x >= lin || (*ita)->getCoordY() + y <= 0 || (*ita)->getCoordY() + y >= lin)

				f = false;
			//Ciclo para verificar posição das outras f = false; else...
		
			else f = true;
			//cout << "preso";
		} while (f == false);
	//	cout << "X:" << x << endl << "Y: " << y << endl;;
		(*ita)->setCoordX(x);
		(*ita)->setCoordY(y);

		
		//(*ita)->setEnergia(-5);
		// Formiga Morre
		/*if ((*ita)->getEnergia() <= 0)
			(*ita)->~Formiga();*/
	}
}
			
}

		
		
	

void Motor::visao()
{
	for (vector<Comunidade*>::const_iterator it = comun.begin();
		it != comun.end(); it++)
	{
		for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin();
			ita != (*it)->getFormigas().end(); ita++)
		{
			for (int i = 0; i < (*ita)->getRaiodeVisao(); i++)
				for (int j = 0; j < (*ita)->getRaiodeVisao(); j++)
					max(abs((*ita)->getCoordX() - i), abs((*ita)->getCoordY() - j));// <= (*ita)->getRaiodeVisao();
		}
	}
}

void Motor::movimento()

 

//	int x =1;
{
	int x = 0;
	int y = 0;
	for (vector<Comunidade*>::const_iterator it = comun.begin();
		it != comun.end(); it++)
	{
		for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin();
			ita != (*it)->getFormigas().end(); ita++)
		{
		//	cout << (*ita)->getRaiomovimento();
			for (int i = 0; i < (*ita)->getRaiomovimento(); i++)
			{
				for (int j = 0 ; j< (*ita)->getRaiomovimento(); j++)
				{
					//cout << "esesers";

					//if (abs((*ita)->getCoordX() - i) < 0 && abs((*ita)->getCoordX() - i) < 0)
					//{
					////	(*ita)->setCoordX(abs((-1)*((*ita)->getCoordX() - i)));
					//	//(*ita)->setCoordY(abs((-1)*((*ita)->getCoordY() - j)));
					//	return				(max(abs((*ita)->getCoordX() - i), abs((*ita)->getCoordY() - j))); //<= (*ita)->getRaiomovimento());
					//}
					//else
//(*ita)->setCoordX(abs(((*ita)->getCoordX() - i)));
//					(*ita)->setCoordY(abs(((*ita)->getCoordY() - j)));
					x = abs((*ita)->getCoordX() - i);
					y = abs((*ita)->getCoordY() - j);
					(*ita)->setCoordX(max(x, y)); //<= (*ita)->getRaiomovimento());
					(*ita)->setCoordY(i + 1);
					//		cout << "filipe -> \t" << (*ita)->getCoordX();

				}

			}
		}

		

		//return x;

	}
	

}


//vector<Formiga*> Motor::mover()
//{
//	//vector<Formiga*>temp;
//	//temp.clear();
//	//for (vector <Comunidade*>::const_iterator it = comun.begin(); it != comun.end(); it++)
//	//{
//	//	for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end(); ita++)
//	//	{
//	//		temp.push_back((*ita));
//	//		(*ita)->move();
//	//	}
//	//}
//
////	return temp;
//	for (vector<Formiga*>::const_iterator it = ants.begin(); it != ants.end(); it++)
//	{
//		(*it)->move();
//	}
//	return ants;
//}
vector<Comunidade*> Motor::getMundo()
{
	for (vector <Comunidade*>::const_iterator ita = comun.begin(); ita != comun.end(); ita++)
	{
		cout << (*ita)->getInfo();
	}
	return comun;
}

vector<Comunidade*> Motor::getComunidade(int id)
{
	
	for (vector <Comunidade*>::const_iterator ita = comun.begin(); ita != comun.end(); ita++)
	{
		if ((*ita)->getID() == id) {
			cout << (*ita)->getInfo();
			(*ita)->getNinho()->getInfoFormigas();
			}
	}
	return comun;
}

void Motor::removeFormiga()
{
	vector<Formiga*> temp;
	for (vector <Comunidade * >::const_iterator it = comun.begin(); it != comun.end(); it++)
	{
		for (vector<Formiga *>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end();)
		{
			if ((*ita)->getEnergia() <= 0)
			{

				delete (*ita);
				ita = (*it)->getFormigas().erase(ita);
			}
			else
				{
					++ita;
				}
		}
	}

	



	
}



// Recebe id da Formiga e remove do Vector
//vector<Formiga*> Motor::removeFormiga(int id)
//{
//	for (vector <Comunidade*>::const_iterator it = comun.begin(); it != comun.end(); it++)
//	{
//		for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end(); ita++) {
//			if ((*ita)->getID() == id) {
//				// Remove Formiga Do Vector
//				(*it)->getFormigas().erase(*ita);
//				*ita++;
//			}
//		}
//	}
//	return ants;
//}

int Motor::getLin()
{
	return lin;
}

int Motor::getTempo()
{
	return tempo;
}
