#include <iostream>
#include <vector>

// stampa semplice del vector
void stampa(const std::vector<int>& v)
{
    if (v.empty()) { std::cout << "(vuoto)\n"; return; }
    for (int i = 0; i < (int)v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v;

    // leggo un po' di valori
    // puoi cambiare come vuoi, anche con input da tastiera
    std::cout << "inserisci quanti mostri: ";
    int n;
    std::cin >> n;

    std::cout << "inserisci le vite:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    std::cout << "\nvettore iniziale:\n";
    stampa(v);

    int round = 1;

    while (true)
    {
        std::vector<int> prima = v;      // mi salvo lo stato per vedere se cambia
        std::vector<int> after = v;      // qui costruisco il risultato del round

        // 1) raddoppio tutte le vite (effetto simultaneo)
        for (int i = 0; i < (int)after.size(); i++)
            after[i] = after[i] * 2;

        // 2) riduzione del vicino sinistro di 1/3 (sempre simultaneo)
        // ogni mostro i toglie after[i]/3 al mostro i-1
        std::vector<int> danni(after.size(), 0);

        for (int i = 0; i < (int)after.size(); i++)
        {
            if (i - 1 >= 0)
                danni[i - 1] += after[i] / 3;
        }

        for (int i = 0; i < (int)after.size(); i++)
        {
            after[i] -= danni[i];
            if (after[i] < 0) after[i] = 0; // non voglio vite negative
        }

        // 3) esplosioni: se vita > 100, elimino lui + vicini
        std::vector<bool> daEliminare(after.size(), false);

        for (int i = 0; i < (int)after.size(); i++)
        {
            if (after[i] > 100)
            {
                daEliminare[i] = true;
                if (i - 1 >= 0) daEliminare[i - 1] = true;
                if (i + 1 < (int)after.size()) daEliminare[i + 1] = true;
            }
        }

        // ricostruisco il vettore finale del round
        std::vector<int> nuovo;
        for (int i = 0; i < (int)after.size(); i++)
        {
            if (!daEliminare[i])
                nuovo.push_back(after[i]);
        }

        v = nuovo;

        // stampa del procedimento (puoi anche toglierla se non la vuoi)
        std::cout << "\nround " << round << ":\n";
        stampa(v);

        // stop: il vettore non cambia piu'
        if (v == prima)
        {
            std::cout << "\nstop: il vettore non cambia piu'\n";
            break;
        }

        // se diventa vuoto, ovviamente non cambiera' piu'
        if (v.empty())
        {
            std::cout << "\nstop: non ci sono piu' mostri\n";
            break;
        }

        round++;
    }

    return 0;
}