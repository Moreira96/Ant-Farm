#include <cstdlib>
#include <cstdio>
#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Formiga;
class Ninho;
class Comunidade;
class Iteraccao;
class Migalhas;
class Motor
{
	vector<string> comandos;
	//vector <Ninho*> ninhos;
	//vector <Formiga*> ants;
	vector <Comunidade*> comun;
	int lin = 10;
	int tempo;
	vector<Migalhas*> mig;
	int pmig;
public:
	Motor();
vector<string> lercomando(string pal,bool *cmd, bool *joga);
bool adiciona(string s, bool *joga);
void mostracomando();
int conta(string s);
Ninho  criaNinho(int l,int c);
~Motor();
vector<Migalhas*>getMigalhas();
vector<Migalhas*>getMigalhasImp();
void adicionaMigalhas(int num);
void criaFormiga(int n, string o, int e);
bool lerdoFicheiro(string pal);
Comunidade &linka( Formiga *b,Ninho *a ,Comunidade *c);
vector <Formiga*> getFormigas();
vector <Formiga *>getFormigasImpTodas();
vector<Comunidade*>getNinhoImprime();
void mover();
void visao();
void movimento();

vector<Comunidade *> getMundo();
vector<Comunidade *> getComunidade(int id);

void removeFormiga();	//Completar

int getLin();
int getTempo();

};





