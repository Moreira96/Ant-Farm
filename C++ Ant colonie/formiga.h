#pragma once
//include "formiga.h"
#include <vector>
#include <string>
class Regras;

using namespace std;
class Ninho;
class Comunidade;
class Formiga
{	
	Ninho *b;
	Comunidade *n;
	int energia;
	char tipo;
	int coordX;
	int coordY;
	int raiomovimento;
    int raiodevisao;
	int id;
	string nome;
	int team;
	static int conta;
	int energiainicial;
	int comun;// ira ser usado para distinguir comunidade!
	int maxx;
	virtual  void adicionaRegra(Regras *x) = 0;
	 vector<Regras*>regras;
public:

	Formiga(int n, const string &s, int c,int tea, int lin);
	Formiga(const Formiga &x);
	void setEnergiaInicial(int i);
	void setEnergia(int e);
    ~Formiga();
	void setRaiodeVisao(int i);
	void setRaiodeMovimento(int t);
	int getCoordX() const;
	int getCoordY() const;
	int getID() const;
	int getLin() const;
	char gettipo() const;
	void setId(int q);
	void visao();
	int getEnergia() const;
//	char getTipo() const;
	int getRaiomovimento() const;
	int getRaiodeVisao() const;
	void adicionaNinho(Ninho *x);
	void adicionaComunidade(Comunidade *x);
	void setCoordX(int a);
	void setCoordY(int y);
	void setTipo(char t);
	int getTeam()const ;
	Ninho & getNinho() const;
	bool distancia(int x, int y);
	int distanciafoge(int x, int y);
	void preencheRegras(Regras *a);
	void move();
	vector<Regras*>& getRegras();
	Comunidade *getComunidade();
	virtual Formiga*duplica()= 0;
	string obtemInfo() const;
};
void menu();