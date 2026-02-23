#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// stampa i mucchi (situazione attuale)
void stampa(const vector<int>& mucchi)
{
    for (int i = 0; i < mucchi.size(); i++)
        cout << mucchi[i] << " ";
    cout << "\n";
}

int main()
{
    srand(time(0));

    vector<int> mucchi;

    // creo 5 mucchi casuali tra 1 e 20
    for (int i = 0; i < 5; i++)
        mucchi.push_back(rand() % 20 + 1);

    cout << "mucchi iniziali:\n";
    stampa(mucchi);
    cout << "\n";

    int totalePrese = 0;
    int turno = 1;

    while (!mucchi.empty())
    {
        int indice = rand() % mucchi.size();   // indice interno
        int mucchioNumero = indice + 1;         // solo per stamparlo come 1..n

        int prese = mucchi[indice] / 2;
        if (prese == 0) prese = 1;

        cout << "turno " << turno << ":\n";
        cout << "la scimmia sceglie il mucchio " << mucchioNumero << "\n";
        cout << "nel mucchio ci sono " << mucchi[indice] << " banane\n";
        cout << "ne prende " << prese << "\n";

        totalePrese += prese;
        mucchi[indice] -= prese;

        if (mucchi[indice] == 0)
        {
            cout << "il mucchio " << mucchioNumero << " si e' svuotato e lo elimino\n";
            mucchi.erase(mucchi.begin() + indice);
        }

        cout << "situazione adesso: ";
        stampa(mucchi);
        cout << "----------------------\n";

        turno++;
    }

    cout << "\ntutte le banane sono finite\n";
    cout << "totale banane prese: " << totalePrese << endl;

    return 0;
}