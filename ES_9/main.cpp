#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

// funzione che stampa le persone rimaste ogni round
void printPeople(const std::vector<std::string>& people, int round)
{
    std::cout << "round " << round << ": ";
    for (int i = 0; i < people.size(); i++)
    {
        std::cout << people[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    // elenco iniziale delle persone
    std::vector<std::string> people = {
        "anna", "luca", "marco", "sara", "giulia", "paolo"
    };

    // generatore random
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));

    int round = 1;

    // tiene conto di quante volte di fila uno riceve scherzi
    std::vector<int> prankStreak(people.size(), 0);

    // continuo finchè rimane più di una persona
    while (people.size() > 1)
    {
        // scelgo indice casuale
        std::uniform_int_distribution<std::size_t> dist(0, people.size() - 1);

        // questo vettore conta quanti scherzi riceve ognuno in questo round
        std::vector<int> received(people.size(), 0);

        // ogni persona fa uno scherzo a qualcuno random
        for (std::size_t i = 0; i < people.size(); i++)
        {
            std::size_t target = dist(rng);
            received[target]++; // aumento contatore
        }

        // aggiorno il contatore degli scherzi consecutivi
        for (std::size_t i = 0; i < prankStreak.size(); i++)
        {
            if (received[i] > 0)
                prankStreak[i]++;  // se ha ricevuto scherzo aumento
            else
                prankStreak[i] = 0; // se no resetto
        }

        // controllo chi deve essere eliminato (parto da destra per non sbagliare con erase)
        for (int i = static_cast<int>(people.size()) - 1; i >= 0; i--)
        {
            if (prankStreak[i] >= 3)
            {
                std::cout << people[i] << " esce per troppi scherzi \n";
                people.erase(people.begin() + i);
                prankStreak.erase(prankStreak.begin() + i);
            }
        }

        printPeople(people, round);
        round++;

        if (people.empty()) break; // sicurezza
    }

    std::cout << "\nrisultato finale: ";

    if (people.empty())
        std::cout << "non è rimasto nessuno \n";
    else
        std::cout << people[0] << " sopravvive \n";

    return 0;
}