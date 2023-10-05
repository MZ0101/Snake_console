#pragma once
#include <iostream>
#include <vector>

#ifndef snake_1
#define snake_1
struct jedzenie {

    int x = 0;
    int y = 0;
   
    
};
struct Wspolzendne
{
    int x=0;
    int y=0;
    Wspolzendne* Node = NULL;
};

class Snake
{
public:
    //arguments
   int n ,k;
   int pkt = 0;
   bool g = true;
   std::string *t = NULL;
   Wspolzendne ost ;
   Wspolzendne *G = nullptr;
   Wspolzendne* second = nullptr;
   std::vector<jedzenie> J ;

    //methods
   
   Snake();
    
    void czyszczenie();
 
    void wyswietlanie();
   
    void zamiana(int &a, int &b);
   
    void dodawanie();
    
    void generacja();
    
    void punkty();

    void menu();

    ~Snake();
   
};

#endif 
