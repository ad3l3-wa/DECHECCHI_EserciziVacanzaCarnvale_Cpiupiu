#include <iostream>
#include <vector>
#include <algorithm>

// stampa il vettore
void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> zombies;
    zombies.push_back(10);
    zombies.push_back(8);
    zombies.push_back(6);
    zombies.push_back(4);
    zombies.push_back(12);

    int round = 1;

    // continuo finchè rimangono almeno 2 zombie
    while (zombies.size() > 1)
    {
        std::cout << "round " << round << ": ";

        // ogni zombie toglie metà della sua vita a quello dopo
        for (int i = 0; i < zombies.size() - 1; i++)
        {
            zombies[i + 1] = zombies[i + 1] - (zombies[i] / 2);
        }

        // tolgo quelli che sono morti (<= 0)
        for (int i = 0; i < zombies.size(); i++)
        {
            if (zombies[i] <= 0)
            {
                zombies.erase(zombies.begin() + i);
                i--; // torno indietro perchè si sposta tutto
            }
        }

        printVector(zombies);

        round++;
    }

    return 0;
}