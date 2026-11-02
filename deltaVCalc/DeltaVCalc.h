#ifndef DeltaVCalc_H
#define DeltaVCalc_H
#include <cmath>
double findDeltaV(double Dry, double Wet, double ISP)
{
    const double g0 = 9.80665;
    double ve = ISP * g0;
    double delta_v = ve * std::log(Wet / Dry);
    return delta_v;
}
#endif // MAIN_H
