#include <iostream>
#include <limits>
#include <cmath>
void clearBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Flushes buffer to prevent infinite loop
}
double getUserInput()
{
    double input{};
    while(true)
    {
        if(!(std::cin >> input) || input <= 0) // Checks if cin fails AND checks if its a negative number
        {
            std::cout << "Please enter a correct value\n";
            // Flushes buffer to prevent infinite loop
            clearBuffer();
        }
        // If theres a valid number leave the loop
        else
        {
            break;
        }
    }
    return input;
}
int getInterestType()
{
    int interestType{};
    while(true)
    {
        std::cout << "Enter the interest type, 1 for simple, 2 for compounding.\n";
        if(!(std::cin >> interestType))
        {
            std::cout << "Please enter 1 or 2\n";
            clearBuffer();
        }
        else if(interestType == 1 || interestType == 2)
        {
            break;
        }
    }
    return interestType;
    return 0;
}
double calculateTotal(double rate, double capital, double timeframe, int interestType)
{
    if(interestType == 1)
    {
        double interest = capital * rate * timeframe;
        double total = capital + interest;
        return total;
    }
    else if(interestType == 2)
    {
        double total = capital * std::pow((1 + rate), timeframe);
        return total;
    }
    return 0;
}
int main()
{
    std::cout << "Enter the yearly interest rate in %\n";
    double rate = getUserInput()/100.0; // Gets the interest in decimal form
    std::cout << "Enter the starting capital\n";
    double capital = getUserInput();
    std::cout << "Enter the timeframe, in years\n";
    double timeframe = getUserInput();
    int interestType = getInterestType();
    double total = calculateTotal(rate, capital, timeframe, interestType);
    std:: cout << "The total amount after " << timeframe << " years is " << total << "$" << '\n';
}
