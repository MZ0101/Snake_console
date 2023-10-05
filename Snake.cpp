#include <iostream>
#include <cstdlib>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include "Snake.hpp"

Snake::Snake()
{
	setlocale(LC_ALL, "Polish");

	std::cout << "Podaj wielkoœæ planszy, na której chcesz graæ : "; 
	std::cin >> n;

	system("cls");
	t = new std::string[n];

	 k = n - 1;
	
	for (int i = 0; i < n; i++)
	{
		t[i].resize(n);
	}
	
	for (int i = 0; i < n; i++)
	{
			t[0][i] = '#';
			t[i][0] = '#';
			t[i][k] = '#';
			t[k][i] = '#';
	}
	
	G = new Wspolzendne;
	G->x = n / 2;
	G->y = n / 2;
	
}
Snake::~Snake()
{
	setlocale(LC_CTYPE, "Polish");

	std::cout << "     KONIEC GRY \n";
	std::cout << "Twoja liczba punktów : " << pkt << "\n";

	delete[] t;
	delete G;
}

void Snake::czyszczenie()
{
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			t[i][j] = ' ';
		}
	}

	for (std::vector<jedzenie>::iterator it = J.begin(); it < J.end(); it++)
	{
		auto pom = it;
		t[pom->x][pom->y] = '$';
	}
}

void Snake::wyswietlanie()
{
	Wspolzendne* pom = G->Node;

	t[G->x][G->y] = 'w';

	ost = *G;

		while (pom != NULL)
			{
				ost = *pom;
				t[pom->x][pom->y] = '+';
				pom = pom->Node;
			}

		if (t[G->x][G->y] == '+')  g = false;

		
		menu();
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
			std::cout << t[i][j] << " ";
			}
			std::cout << "\n";
		}

}

void  Snake::zamiana(int &a, int &b)
{
	Wspolzendne* pom = G->Node;
	Wspolzendne pom_1;
	pom_1 = *G;

	Wspolzendne pom_2;
	second = pom;

	G->x = G->x + a;
	G->y = G->y + b;

	if (second != NULL && second->x == G->x && second->y == G->y)
	{
		a = -a;
		b = -b;
		G->x = G->x + 2*a;
		G->y = G->y + 2*b;
	}

	if (t[G->x][G->y] == '$') { punkty(); generacja(); }
		else if (G->x == k) G->x = 1;
		else if (G->y == k) G->y = 1;
		else if (G->x == 0) G->x = n - 2;
		else if (G->y == 0) G->y = n - 2;

			while (pom != NULL)
			{
				pom_2 = *pom;
				pom->x = pom_1.x;
				pom->y = pom_1.y;
				pom_1 = pom_2;
				pom = pom->Node;
			}
		
}

void Snake::dodawanie()
{
	pkt++;

	int x, y;
	Wspolzendne* pom = G;

	while (pom->Node != NULL)
	{
		pom = pom->Node;
	}
	Wspolzendne* pom_1 = new Wspolzendne;
	x = ost.x;
	y = ost.y;

	pom_1->x = x;
	pom_1->y = y;

	pom->Node = pom_1;
}

void Snake::generacja()
{
	int x = 0;
	int y = 0;

	while (t[x][y] != ' ')
	{
		x = (rand() % k) + 1;
		y = (rand() % k) + 1;
	}
	jedzenie pom;
	pom.x = x;
	pom.y = y;

	J.emplace(J.end(), pom);
}

void Snake::punkty()
{
	int j = 0;

	while (J[j].x != G->x && J[j].y != G->y) { j++; }

	J.erase(J.begin() + j);
	dodawanie();
}

void Snake::menu()
{
	setlocale(LC_CTYPE, "Polish");

	std::cout << "          Snake \n";
	std::cout << "____________________________\n\n";
	std::cout << "W prawo: D         W lewo: A\n";
	std::cout << "W dól: S           W góre: W\n";
	std::cout << "Twoja liczba punktów : "<<pkt<<"\n\n";
	std::cout << "____________________________\n\n";
}