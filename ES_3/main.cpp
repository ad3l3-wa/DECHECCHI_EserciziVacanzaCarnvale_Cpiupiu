#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// stampa il vettore di stringhe
void printVector(const std::vector<std::string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

// ritorna un nome di gatto a caso
std::string randomCat()
{
    std::vector<std::string> names;
    names.push_back("Milo");
    names.push_back("Luna");
    names.push_back("Oliver");
    names.push_back("Leo");
    names.push_back("Max");
    names.push_back("Bella");
    names.push_back("Misty");
    names.push_back("Nala");
    names.push_back("Simba");
    names.push_back("Mochi");

    int index = std::rand() % names.size();
    return names[index];
}

int main()
{
    std::srand(std::time(0)); // inizializzo il random

    std::vector<std::string> cats;

    // metto 4 gatti iniziali
    for (int i = 0; i < 4; i++)
    {
        cats.push_back(randomCat());
    }

    // faccio 11 secondi (da 0 a 10)
    for (int second = 0; second <= 10; second++)
    {
        // sposto l'ultimo gatto in prima posizione (tipo rotate)
        std::string last = cats[cats.size() - 1];
        cats.pop_back();
        cats.insert(cats.begin(), last);

        // se l'ultimo nome inizia con M aggiungo un gatto all'inizio
        if (!cats.empty() && cats[cats.size() - 1][0] == 'M')
        {
            cats.insert(cats.begin(), randomCat());
        }

        std::cout << "secondo " << second << ": ";
        printVector(cats);
    }

    return 0;
}