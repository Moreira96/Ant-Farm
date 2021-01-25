
#pragma once
#include <vector>

using namespace std;

class Ninho;
class Formiga;

class Comunidade
{
	const int POSX;
	const int POSY;
	int num;
	int limite;
	Ninho *ninho;
	vector <Formiga*>fomigas;
	 int id;
public:

	Comunidade(int q, int d);
	int getX() const;
	int getY() const;
	
	void adicionaformiga(Formiga *a);
	void adicionaNinho(Ninho *b);
	static int conta;
	vector <Formiga*>& getFormigas();
	void mostraInfo() const;
	string getInfo() const; 
	int getID() const;
	void  setID(int b);
	Ninho * getNinho()const;
	~Comunidade();
};