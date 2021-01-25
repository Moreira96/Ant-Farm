#include "leituradecomandos.h"
#include <math.h>
#include <algorithm>
#include "Consola.h"
#include "formiga.h"
#include "Ninho.h"
#include "Comunidade.h"
#include "Exploradora.h"
int Formiga::conta = 1;

Formiga::Formiga(int n,const string &s, int c,int tea, int lin)
{	
	coordX = n;
	coordY = c;
	maxx = lin;
	if (s.compare("c")== 0)
	{
		//nome = "cuidadora";
	//	coordX = n;
		//coordY = c;
		//energia = 100;
//		raiomovimento = 3;
	//	raiodevisao = 5;
		//tipo = 'C';
		id = conta++;
		team = tea;
	
	}
	else
		if (s.compare("v") == 0)
	{
		//nome = "vigilante";
		//coordX = n;
		//coordY = c;
		//energia = 150;
		//raiomovimento = 5;
		//raiodevisao = 7;
		//tipo = 'V';
		id = conta++;
		team = tea;
	}
	else
		if (s.compare("a") == 0)
	{
		/*nome ="assaltante" ;
		coordX = n;
		coordY = c;
		energia = 80;
		raiomovimento = 4;
		raiodevisao = 8;
		tipo = 'A';*/
		id = conta++;
		team = tea;
	}
	else
		if (s.compare("e") == 0)
	{
			
		/*nome = "exploradora";
		coordX = n;
		coordY = c;
		energia = 200;
		raiomovimento = 8;
		raiodevisao = 10;
		tipo = 'E';*/
		id = conta++;
		team = tea;
	}
	else
		if (s.compare("s") == 0)
		
	{
	/*	nome = "surpresa";
		coordX = n;
		coordY = c;
		energia = 100;
		raiomovimento = 3;
		raiodevisao = 5;
		tipo = 'S';
	*/	id = conta++;
		team = tea;
	}
	else
		cout << "NAO EXISTE ESSE TIPO \n ";
}
int Formiga::getLin()const

{
	return maxx; 
}
Formiga::Formiga(const Formiga &x)
{
	/*coordX = x.coordX;
	coordY = x.coordY;
	energia = x.energia;
	raiomovimento = x.raiomovimento;
	raiodevisao = x.raiodevisao;
	tipo = x.tipo;
	n = x.n;*/
}

void Formiga::setEnergiaInicial(int i)
{
	energiainicial = i;
	//energia = 5;// energiainicial;
}

void  menu()
{
    string tipo;
	int x; 
	int y;
	cout << "Introduza tipo : ";
	cin >> tipo;
	cout << endl;
	cout << "Introduza coordenadas x e y ";
	cin >> x >> y;
}

Formiga::~Formiga()
{

	// Falta remover dos Vetores (Ninho???)

	cout << "Destruindo formiga do Ninho " << b->getID() << " da comunidade" << n->getID() << "do tipo  " << gettipo();
	n = nullptr;
	b = nullptr;
}

void Formiga::setRaiodeVisao(int i)
{
	raiodevisao = i;
}

int Formiga::getCoordX() const
{
	return coordX;
}

int Formiga::getID() const
{
	return id;
}
void Formiga::setId(int q)
{
	id = q;
}

int Formiga::getCoordY() const
{
	return coordY;
}
//
//string Formiga::getNome() const
//{
//	return nome;
//}
//
int Formiga::getEnergia() const
{
	return energia;
}

int Formiga::getRaiomovimento() const
{
	return raiomovimento;
}

int Formiga::getRaiodeVisao() const
{
	return raiodevisao;
}

char Formiga::gettipo() const
{
	return tipo;
}

void Formiga::setTipo(char t)
{
	tipo = t;
}
void Formiga::setRaiodeMovimento(int t)
{
	raiomovimento = t;
}

//int Formiga::getRaiomovimento() const
//{
//	return raiomovimento;
//}
//
//int Formiga::getRaiodeVisao() const
//{
//	return raiodevisao;
//}
//
void Formiga::setCoordX(int a)
{
	coordX += a;
}
void Formiga::setCoordY(int y)
{
	coordY += y;
}

void Formiga::setEnergia(int e)
{
	energia += e;
}

//void Formiga::setTipo(char t)
//{
//	tipo = t;
//}
int Formiga::getTeam() const
{
	return team;
}

/*
void Formiga::move()
{
	int x, y, r;
	bool f = false;
	do {
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

		if (coordX + x <= 0 || coordX + x >= max || coordY + y <= 0 || coordY + y >= max)
			f = false;
		else f = true;
		//cout << " ESTOU PRESO";
	} while (f == false);
	coordX += x;
	coordY += y;
	//cout << "vou sair";
	return;
}
*/
string Formiga::obtemInfo() const
{
	ostringstream oss;

	oss << "\n\tINFO DA FORMIGA :" << endl; 

	{
		oss << "\n  Formiga de tipo: \t" << tipo << "\n  Coordenada X: \t\t" << coordX << "\n  Coordenada Y: \t\t" << coordY << "\n  Energia: \t\t" <<
			energia << "\n  ID:\t\t\t" << id << "\nPONTEIRO PARA COMUNIDADE " << n <<endl;
			//<< "\n PONTEIRO PARA NINHO = "<< b << 
	}
	return oss.str();
}

void Formiga::adicionaNinho( Ninho *x)
{
	b = x;
}
void Formiga::adicionaComunidade(Comunidade *x)
{
	n = x;
}
Ninho & Formiga::getNinho() const
{
	
	return *b;
}

void Formiga::adicionaRegra(Regras * x)
{
	regras.push_back(x);
}
//
vector<Regras*>& Formiga::getRegras()
{
	return regras;
}

Comunidade * Formiga::getComunidade()
{
	// TODO: inserir instrução de retorno aqui
	return n;
}


bool Formiga::distancia(int x, int y)
{
	int a, b;

	a = (this)->getCoordX();
	b = (this)->getCoordY();


	if (max(a - x, b - y) <= (this)->getRaiodeVisao())
		return true;//perigo
	else
		return false; //livre
}

int Formiga::distanciafoge(int x, int  y)
{
	int a, b;

	a = (this)->getCoordX();
	b = (this)->getCoordY();

	//cout << "sasd " << a << " bota " << x;
	if (max(a - x, b - y) <= (this)->getRaiomovimento())
		if (max(a - x, b - y) < 0)
			return ((-1)*max(a - x, b - y)/3);
		else
		return (max(a - x, b - y)/3);
		
	else
		return 0;

}

void Formiga::preencheRegras(Regras * a)
{
	regras.push_back(a);
}

