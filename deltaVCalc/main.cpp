#include <iostream>
#include "DeltaVCalc.h"

int main()
{
    std::cout << "--------------Delta V calculator--------------\n";
    std::cout << "Enter the dry mass of the vehicle (kg).\n";
    double Dry{};
    std::cin >> Dry;
    std::cout << "Enter the wet mass of the vehicle (kg)\n";
    double Wet{};
    std::cin >> Wet;
    if (Dry >= Wet) {
        std::cout << "Error, dry mass cannot be larger than wet mass\n";
        return 1;
    }
    std::cout << "Enter the ISP (in seconds)\n";
    double ISP{};
    std::cin >> ISP;
    std::cout << "Delta-v: " << findDeltaV(Dry, Wet, ISP) << " m/s" << '\n';

    return 0;
}
