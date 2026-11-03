#include <iostream>
#include <limits>
// Struct to keep code readable.
struct resources{
    int farms = 0;
    int population = 15; // Total population including workers
    int money = 100;
    int food = 20;
    int workers = 0; // Employed population
};
void clearBuffer() // Used for input validation
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int getUnemployed(const resources& res)
{
    int unemployed = res.population - res.workers;
    return unemployed;
}
void buyFarm(resources& res)
{
    while(true)
    {
        if(res.money < 25 || getUnemployed(res) < 3 ) // set to 25 cause farms cost 25, set to 3 because farms need 3 workers
        {
            std::cout << "Cannot buy a farm, not enough population/money\n";
            break;
        }
        res.farms++;
        res.money -= 25;
        res.workers += 3;
        std::cout << "+1\n";
        if(res.money < 25 || getUnemployed(res) < 3 ) // set to 25 cause farms cost 25, set to 3 because farms need 3 workers
        {
            std::cout << "Cannot buy a farm, not enough population/money\n";
            break;
        }
        std::cout << "Again? 1 for yes 2 for no.\n";
        int choice{};
        if(!(std::cin >> choice)) // If user enters a letter it leaves the loop
        {
            clearBuffer();
            break;
        }
        if(choice == 2)
        {
            break;
        }
    }
}
void updateTurn (resources& res) // Updates every resource
{
    res.food += res.farms * 5; // Each farm makes 5 food
    res.food -= res.population; // Each population eats 1 food
    if(res.food >= 10) // Causes population growth
    {
        res.population+= (res.food - 10)/2; // For every +2 food above 10 gain 1 population
    }
    else if(res.food <=0) // Causes population decline, loses 5 as soon as it hits 0
    {
        res.population+=(res.food - 10)/2; // For every -2 food below 0 lose 1 population
        res.food = 0; // You cant have negative food
    }
    if (res.workers > res.population) // If there are more workers then population they die
                                      // This is so the workers die last
    {
        res.workers = res.population;
    }
    res.money += res.workers * 2; // Each worker makes 2 money
    while(res.farms * 3 > res.workers) // Deletes farms if there isnt enough workers to staff them
    {
        res.farms--;
    }
}
int main()
{
    resources res;
    while(true)
    {
        if(res.population <=0) // Checks for lose condition
        {
            std::cout << "Game over\n";
            break;
        }
        else if(res.money >= 1000) // Checks for win condition
        {
            std::cout << "Winner\n";
            break;
        }

        std::cout << "Farms: " << res.farms << '\n';
        std::cout << "Total population: " << res.population << '\n';
        std::cout << "Money: " << res.money << '\n';
        std::cout << "Food: " << res.food << '\n';
        std::cout << "Employed population: " << res.workers << '\n';
        std::cout << "What would you like to do?\n"
                  << "1. Buy farm\n"
                  << "2. Exit game\n"
                  << "3. Proceed to next turn\n";
        int choice{};
        if (!(std::cin >> choice)) // Input validation so letters dont crash the program
        {
            std::cout << "Invalid input. Please enter a number.\n";
            clearBuffer();
            continue;
        }
        if(choice == 1)
        {
            buyFarm(res);
        }
        else if(choice == 2)
        {
            std::cout << "Goodbye\n";
            break;
        }
        else if(choice == 3)
        {
            updateTurn(res);
        }
        else
        {
            std::cout << "Invalid choice, try again.\n";
            continue;
        }
    }
    return 0;
}
