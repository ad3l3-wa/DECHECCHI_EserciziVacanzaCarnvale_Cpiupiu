#include <iostream>
#include <vector>
#include <algorithm>

// stampa i robot
void printRobots(const std::vector<int>& robots, int round)
{
    std::cout << "round " << round << ": ";
    for (int i = 0; i < robots.size(); i++)
    {
        std::cout << robots[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> robots;
    robots.push_back(1);
    robots.push_back(3);
    robots.push_back(5);
    robots.push_back(7);
    robots.push_back(9);

    int round = 1;

    // continuo finchè ci sono almeno 2 robot
    while (!robots.empty() && robots.size() > 1)
    {
        // raddoppio tutti i valori (x = x + x)
        for (int i = 0; i < robots.size(); i++)
        {
            robots[i] = robots[i] + robots[i];
        }

        // ordino così i duplicati stanno vicini
        std::sort(robots.begin(), robots.end());

        // tolgo i duplicati (se sono uguali consecutivi)
        for (int i = 0; i < robots.size() - 1; i++)
        {
            if (robots[i] == robots[i + 1])
            {
                robots.erase(robots.begin() + (i + 1));
                i--; // torno indietro perchè si sposta tutto
            }
        }

        // stampo il round
        printRobots(robots, round);
        round++;
    }

    return 0;
}