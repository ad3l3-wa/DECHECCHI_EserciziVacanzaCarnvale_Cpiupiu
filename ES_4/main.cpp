#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0)); //sempre se random

    std::vector<int> v;

    std::cout << "ciao,inserisci 10 numeri :) :\n";
    for (int i = 0; i < 10; i++) //legge per 10 volte
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < 20; i++)
    {
        int a = rand() % 10; //praticamente mi genera un numero casuale grande ma me lo limita tra 0 e la lunghezza del vettore -1
        int b = rand() % 10;

        std::swap(v[a], v[b]); //mi scambia i valori in posizione a e in posizione b e sto lo fa 20 volte
    }

    int somma = 0;

    for (int i = 0; i < v.size(); i++)  //somma classica
    {
        somma += v[i];
    }

    std::cout << "\nvettore finale:\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\nla somma e' = " << somma << std::endl;

    return 0;
}