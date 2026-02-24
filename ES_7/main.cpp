#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

// stampa il vettore dei colori
void printColors(const std::vector<char>& colors, int round)
{
    std::cout << "round " << round << ": ";
    for (int i = 0; i < colors.size(); i++)
    {
        std::cout << colors[i] << " ";
    }
    std::cout << "\n";
}

// elimina tre lettere uguali consecutive
void removeTriplets(std::vector<char>& colors)
{
    // controllo finchè ci sono almeno 3 elementi
    for (int i = 0; i + 2 < colors.size(); )
    {
        // se trovo tre uguali di fila
        if (colors[i] == colors[i + 1] && colors[i] == colors[i + 2])
        {
            // elimino questi tre
            colors.erase(colors.begin() + i, colors.begin() + i + 3);
        }
        else
        {
            i++; // vado avanti
        }
    }
}

int main()
{
    std::vector<char> colors;

    // metto dentro le lettere da A a Z
    for (char c = 'A'; c <= 'Z'; c++)
    {
        colors.push_back(c);
    }

    // generatore numeri casuali
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));

    int round = 1;

    // continuo finchè restano più di 10 lettere
    while (colors.size() > 10)
    {
        // scelgo due posizioni casuali
        std::uniform_int_distribution<std::size_t> dist(0, colors.size() - 1);

        std::size_t i = dist(rng);
        std::size_t j = dist(rng);

        // scambio le due lettere
        std::swap(colors[i], colors[j]);

        // controllo se ci sono triplette
        removeTriplets(colors);

        // stampo situazione attuale
        printColors(colors, round);

        round++;
    }

    return 0;
}