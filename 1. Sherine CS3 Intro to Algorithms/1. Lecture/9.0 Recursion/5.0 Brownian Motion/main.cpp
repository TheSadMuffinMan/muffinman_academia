#include <iostream>
#include <cmath>
#include <random>

class Brownian {
    public:
        static void curve(double x0, double y0, double x1,
        double y1, double var, double s)
        {
            if (x1 - x0 < 0.01)
            {
                std::cout << "Draw line from (" << x0 << ", "
                << y0 << ") to (" << x1 << ", " << y1 << ")\n";
                return;
            }

            double xm = (x0 + x1) / 2;
            double ym = (y0 + y1) / 2;
            double stddev = sqrt(var);
            double delta = gaussian(0, stddev);
            curve(x0, y0, xm, ym + delta, var / s, s);
            curve(xm, ym + delta, x1, y1, var / s, s);
        }

        static double gaussian(double mean, double stddev)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<double> dist(mean, stddev);
            return dist(gen);
        }
};

int main(int argc, char* argv[])
{
    double hurst = 0.0;
    std::cout << "\nPlease input Hurst Value: ";
    std::cin >> hurst;
    
    double s = pow(2, 2 * hurst);
    Brownian::curve(0, 0.5, 1.0, 0.5, 0.01, s);
    return 0;
}