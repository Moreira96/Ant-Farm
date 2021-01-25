#include "Iteraccao.h"
#include "leituradecomandos.h"
#include "Consola.h"
#include "Comunidade.h"
#include "formiga.h"
#include "Ninho.h"

int main(int argc, char **argv)
{
	{


		Motor m;
		Iteraccao a(&m);
		do
		{
			a.getComando();
			a.printMapa(0, 0);
		} while (1);
		system("pause");
	}
}