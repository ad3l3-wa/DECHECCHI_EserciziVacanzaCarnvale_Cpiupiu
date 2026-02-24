#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // inizializzo il random

    // creo la matrice 5x5
    std::vector<std::vector<int>> matrice(5, std::vector<int>(5));

    // riempio la matrice con numeri casuali da 1 a 10
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrice[i][j] = std::rand() % 10 + 1;
        }
    }

    std::cout << "matrice iniziale:\n";

    // stampo la matrice
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nnuovi vettori:\n";

    // per ogni riga creo un nuovo vettore
    for (int i = 0; i < 5; i++)
    {
        std::vector<int> nuovo; // qui salvo solo i numeri pari
        int somma = 0; // per calcolare la somma dei pari

        for (int j = 0; j < 5; j++)
        {
            // controllo se il numero è pari
            if (matrice[i][j] % 2 == 0)
            {
                nuovo.push_back(matrice[i][j]); // aggiungo al nuovo vettore
                somma += matrice[i][j]; // aggiorno la somma
            }
        }

        // alla fine aggiungo la somma dei pari
        nuovo.push_back(somma);

        // stampo il nuovo vettore
        for (int k = 0; k < nuovo.size(); k++)
        {
            std::cout << nuovo[k] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}