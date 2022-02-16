#include <cmath>

const double PI = 3.14159265;

double s_calculation(double x, double y, double z)
{
    return 1 + sqrt(pow(x / abs(y - z), 3) +
          (pow(x, 2) + z) / sqrt(abs((z + x) * y)) -
            cos(x * pow(z, 2)) / (2 * y + PI));
}
