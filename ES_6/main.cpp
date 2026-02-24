#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// stampa i mucchi (situazione attuale)
void stampa(const std::vector<int>& mucchi)
{
    for (int i = 0; i < static_cast<int>(mucchi.size()); i++)
        std::cout << mucchi[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::vector<int> mucchi;

    // creo 5 mucchi casuali tra 1 e 20
    for (int i = 0; i < 5; i++)
        mucchi.push_back(std::rand() % 20 + 1);

    std::cout << "mucchi iniziali:\n";
    stampa(mucchi);
    std::cout << "\n";

    int totalePrese = 0;
    int turno = 1;

    while (!mucchi.empty())
    {
        int indice = std::rand() % static_cast<int>(mucchi.size()); // indice interno
        int mucchioNumero = indice + 1; // solo per stamparlo come 1..n

        int prese = mucchi[indice] / 2;
        if (prese == 0) prese = 1;

        std::cout << "turno " << turno << ":\n";
        std::cout << "la scimmia sceglie il mucchio " << mucchioNumero << "\n";
        std::cout << "nel mucchio ci sono " << mucchi[indice] << " banane\n";
        std::cout << "ne prende " << prese << "\n";

        totalePrese += prese;
        mucchi[indice] -= prese;

        if (mucchi[indice] == 0)
        {
            std::cout << "il mucchio " << mucchioNumero << " si e' svuotato e lo elimino\n";
            mucchi.erase(mucchi.begin() + indice);
        }

        std::cout << "situazione adesso: ";
        stampa(mucchi);
        std::cout << "----------------------\n";

        turno++;
    }

    std::cout << "\ntutte le banane sono finite\n";
    std::cout << "totale banane prese: " << totalePrese << std::endl;

    return 0;
}