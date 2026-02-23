#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void stampa(const std::vector<int>& v)
{
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main()
{
    srand(time(0)); //devo peffrza metterlo se faccio un random

    std::vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(rand() % 100 + 1); //numeri casuali da 1 a 100 e gli metti uno dopo l'altro con push back

    std::cout << "Vettore iniziale:\n";
    stampa(v);

    while (v.size() <= 50) //continuofinche non arrivo a 50
    {
        bool trovatoMultiplo = false;


        for (int i = 0; i < (int)v.size(); i++)
        {
            if (v[i] % 7 == 0) //cerco i multipli di 7
            {
                trovatoMultiplo = true;

                v.erase(v.begin() + i); //!!!ricorda!!!!!!!erase per elimare e begin praticamente parte dal prmo e con +i gli scorre

                int sizeAttuale = (int)v.size();
                for (int j = 0; j < sizeAttuale; j++)
                {
                    if (v[j] % 2 == 0) //trovo i divisibili di due e gli ricopio
                        v.push_back(v[j]);
                }

                // riparto da capo (esco dal for, torno al while)
                break;
            }
        }

//esco se nin ho trovato multipli
        if (!trovatoMultiplo) {
            break;
        }
    }

    std::cout << "\necco il vettore:\n";
    stampa(v);


    if (v.size() <= 50)
        std::cout << "\nMi sono fermato perche' non ci sono piu' multipli di 7.\n";
    else
        std::cout << "\nMi sono fermato perche' il vettore ha superato 50 elementi.\n";

    return 0;
}