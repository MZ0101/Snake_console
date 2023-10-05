#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Snake.hpp"

int main()
{
    Snake a;
    int i = 0;
    int x = -1;
    int y = 0;

    while (a.g)
    {
        a.czyszczenie();
        
        if (GetAsyncKeyState(0x41)) { x = 0; y = -1; }
        if (GetAsyncKeyState(0x44)) { x = 0; y = 1; }
        if (GetAsyncKeyState(0x57)) { x = -1; y = 0; } 
        if (GetAsyncKeyState(0x53)) { x = 1; y = 0; }

        a.zamiana(x,y);

        a.wyswietlanie();

        Sleep(150);
        if(i%10==0 && i<=100) a.generacja();
        system("cls");
        i++;
    }
    
    return 0;
}

