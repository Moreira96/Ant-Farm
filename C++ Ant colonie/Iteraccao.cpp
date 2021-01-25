#include "Iteraccao.h"
#include "Consola.h"
#include "leituradecomandos.h"
#include "Ninho.h"
#include "formiga.h"
#include "Comunidade.h"
#include "Exploradora.h"
#include <iostream>
#include <sstream>
#include <limits>
#include "Migalhas.h"
#include <time.h>

int Iteraccao::contatempo = 0;

Iteraccao::Iteraccao(Motor *n)
{
	Consola::setScreenSize(30, 155);
	Consola::setTextSize(20, 20);
	Consola::setTextColor(Consola::PRETO);
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	criaMapa();
	criaConsola();
	m = n;
}

void Iteraccao::criaMapa()
	{
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < lin; j++) {
			mapa[i][j] = char(176);
			cor[i][j] = 0;
		}
		}
	}

void Iteraccao::printConsola(int x, int y, char *m, int str, int yy)
{
	Consola::gotoxy(yy, str);
	int j = 0, a = 0;
	for (int i = 0; i < y*x; i++) {
		cout << *(m + i);
		a++;
		if (a >= y) {
			j++;
			a = 0;
			Consola::gotoxy(yy, str + j);
		}
	}
}

	void Iteraccao::criaConsola()
	{
		int str = 0;
		const int x = 4, y = 115, xx = 25, yy = 115, xxx = 29, yyy = 40;

		char con[x][y], ecr[xx][yy], info[xxx][yyy];
		for (int i = 0; i < xx; i++) {
			for (int j = 0; j < yy; j++) {
				if (i == 0 && j == 0)
					ecr[i][j] = char(201);
				else
					if (i == 0 && j == yy - 1)
						ecr[i][j] = char(187);
					else
						if (i == xx - 1 && j == 0)
							ecr[i][j] = char(200);
						else
							if (i == xx - 1 && j == yy - 1)
								ecr[i][j] = char(188);
							else
								if (j == 0 || j == yy - 1)
									ecr[i][j] = char(186);
								else
									if (i == 0 || i == xx - 1)
										ecr[i][j] = char(205);
									else ecr[i][j] = ' ';
			}
		}
		printConsola(xx, yy, (char *)ecr, 0, 40);
		{
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					if (i == 0 && j == 0)
						con[i][j] = char(201);
					else
						if (i == 0 && j == y - 1)
							con[i][j] = char(187);
						else
							if (i == x - 1 && j == 0)
								con[i][j] = char(200);
							else
								if (i == x - 1 && j == y - 1)
									con[i][j] = char(188);
								else
									if (j == 0 || j == y - 1)
										con[i][j] = char(186);
									else
										if (i == 0 || i == x - 1)
											con[i][j] = char(205);
										else con[i][j] = ' ';
				}
			}
		}
		str = 25;
		printConsola(x, y, (char *)con, str, 40);
		{
			for (int i = 0; i < xxx; i++) {
				for (int j = 0; j < yyy; j++) {
					if (i == 0 && j == 0)
						info[i][j] = char(201);
					else
						if (i == 0 && j == yyy - 1)
							info[i][j] = char(187);
						else
							if (i == xxx - 1 && j == 0)
								info[i][j] = char(200);
							else
								if (i == xxx - 1 && j == yyy - 1)
									info[i][j] = char(188);
								else
									if (j == 0 || j == yyy - 1)
										info[i][j] = char(186);
									else
										if (i == 0 || i == xxx - 1)
											info[i][j] = char(205);
										else info[i][j] = ' ';
				}
			}
		}
		str = 0;
		printConsola(xxx, yyy, (char *)info, str, 0);
		Consola::gotoxy(9, 0);
		cout << " Informa" << char(135) << "ao do Jogo ";
	}

	void Iteraccao::ImprimeFormigaTodas()
	{
		vector <Formiga*>temp;
		
		temp.clear();
			
		temp=m->getFormigasImpTodas();
		for (vector<Formiga*>::const_iterator it = temp.begin();
			it != temp.end(); it++)
			{
			 
				mapa[(*it)->getCoordX()][(*it)->getCoordY()] = (*it)->gettipo();
				cor[(*it)->getCoordX()][(*it)->getCoordY()] = (*it)->getTeam();
			}
		
	}

	void Iteraccao::ImprimeNinhos()
	{
		vector <Comunidade*> temp;

		temp = m->getNinhoImprime();
	
		for (vector<Comunidade*>::const_iterator it = temp.begin();
			it != temp.end(); it++)
			
		{
				mapa[(*it)->getNinho()->getX()][(*it)->getNinho()->getY()] =(*it)->getNinho()->getTipo();
				cor[(*it)->getNinho()->getX()][(*it)->getNinho()->getY()] = (*it)->getNinho()->getId();
		}		
	}

	void Iteraccao::contadordetempo()
	{
		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {}
		contatempo++;
	}

	// Teste movimento

	void Iteraccao::moveTudo() {
		m->mover();
		
	}

	//	----------------------------------------------- B4ckUp ! ! ! ------------------------------------------------------------------------------------------------
	/*void Iteraccao:: moveTudo()
	{
		
			vector <Comunidade*> temp;
			vector<Formiga*> temp2;
			temp = m->getNinhoImprime();

			for (vector<Comunidade*>::const_iterator it = temp.begin();
				it != temp.end(); it++)
			{
				for (vector<Formiga*>::const_iterator ita = (*it)->getFormigas().begin(); ita != (*it)->getFormigas().end(); ita++)
				{
					temp2.push_back((*ita));
				}
			}

			for (vector<Formiga*>::const_iterator ita = temp2.begin(); ita != temp2.end(); ita++)
			{
				//for (vector<Formiga*>::const_iterator it = temp2.begin(); it != temp2.end(); it++)
				{
					//if (((*it)->getCoordX()) != ((*ita)->getCoordX()) && (((*it)->getCoordY()) != (*ita)->getCoordY()))
					{

						(*ita)->move();
					}
				}
			}
			
			
	}
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	*/

	void Iteraccao::ImprimeMigalhas()
	{
		{
			vector <Migalhas*> temp;

			temp = m->getMigalhasImp();

			for (vector<Migalhas*>::const_iterator it = temp.begin();
				it != temp.end(); it++)

			{
				mapa[(*it)->getX()][(*it)->getY()] = 'M';
				cor[(*it)->getX()][(*it)->getY()] = 9;
			}
		}
	}
	void Iteraccao:: comandotempo( int x)
	{
		contatempo = 0;
		do
		{
			int max, maxy;

			Consola::gotoxy(1, 1);
			m->removeFormiga();


			ImprimeFormigaTodas();
			ImprimeNinhos();
			ImprimeMigalhas();
			contadordetempo();
			moveTudo();
			Consola::gotoxy(41, 1);
			if (lin <= 24)
				maxy = max = lin;
			else {
				max = 24;
				maxy = 100;
			}
			for (int i = 0; i < max; i++) {
				for (int j = 0; j < maxy; j++) {
					Consola::setTextColor(Consola::PRETO + cor[i][j]);
					cout << mapa[i][j];
					if (mapa[i][j] != char(176) && contatempo < x - 1)
					{
						mapa[i][j] = char(176);
						cor[i][j] = 0;
					}
				}
				Consola::gotoxy(41, 1 + i);
			}
			//system("pause");
		} while (contatempo < x-1);
		
		joga = false;
	}



	void Iteraccao::printMapa(int x, int y)
	{
		int max, maxy;

		Consola::gotoxy(1, 1);

		ImprimeFormigaTodas();
		ImprimeNinhos();
		ImprimeMigalhas();
		
		if (joga == 1)
			comandotempo(tempo);

		Consola::gotoxy(41, 1);
		if (lin <= 24)
			maxy = max = lin;
		else {
			max = 24;
			maxy = 100;
		}
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < maxy; j++) {
				Consola::setTextColor(Consola::PRETO + cor[i][j]);
				cout << mapa[i][j];
			}
			Consola::gotoxy(41, 1 + i);
		}
	}

Iteraccao::~Iteraccao()
{
	cout << "A desligar a iteraccao ";
}

void Iteraccao::getComando()
{
	string pal;
	bool cmd = false;

	Consola::setTextColor(Consola::PRETO);
	Consola::gotoxy(42, 27);
	cout << "Comando >> ";
	Consola::gotoxy(53, 27);

	getline(cin, pal);
	criaConsola();
	m->lercomando(pal, &cmd, &joga);

	if (cmd == false) {
		Consola::gotoxy(43, 26);
		cout << "Comando Errado";
		Consola::gotoxy(42, 27);
		cout << "Comando >> ";
		cout << "                                                                                                     ";
		Consola::gotoxy(53, 27);
	}
	else {
		Consola::gotoxy(42, 26);
		cout << "                                                                                                     ";
		Consola::gotoxy(42, 27);
		cout << "Comando >> ";
		cout << "                                                                                                     ";
		Consola::gotoxy(53, 27);
		if (m->getLin() != lin) {
			lin = m->getLin();
			criaMapa();
		}
		if (m->getTempo() != tempo)
			tempo = m->getTempo();
	}
}