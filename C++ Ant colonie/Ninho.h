#pragma once

#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Formiga;

class Ninho {
	static int conta;
	const int x;//Posição x
	const int y;//Posição y
	int energ;	//Energia
	const int id;	//Conta total de ninhos para ID
   //Guarda formidas do ninho
	char tipo = 'N';
	vector <Formiga *> formig;
public:
	//Ninho ();
	//Ninho(const Formiga * const a);
	Ninho(int xx, int yy, int energia);
	string  getAsString() const;
void adicionaFormiga( Formiga *f);

int getID() const;
    void  mostraInfoNinho() const ;
	//bool SomaEnergiaNinho(Formiga *f);
	vector<Formiga*> getInfoFormigas();
	int getId() const; 
	int getX() const;
	int getY() const;
	int getEnergiaNinho() const;
	char getTipo() const;
	~Ninho();

};