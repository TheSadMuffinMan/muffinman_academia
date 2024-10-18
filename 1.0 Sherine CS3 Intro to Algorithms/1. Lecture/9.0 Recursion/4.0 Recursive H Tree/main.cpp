/*
This program is known as a recursive H Tree.
*/

#include <iostream>

class Htree {
    public:
        static void draw(int n, double sz, double x, double y)
        {
            if (n == 0) {return;}

            double x0 = x - sz / 2, x1 = x + sz / 2;
            double y0 = y - sz / 2, y1 = y + sz / 2;
            drawLine(x0, y, x1, y);
            drawLine(x0, y0, x0, y1);
            drawLine(x1, y0, x1, y1);
            draw(n - 1, sz / 2, x0, y0);
            draw(n - 1, sz / 2, x0, y1);
            draw(n - 1, sz / 2, x1, y0);
            draw(n - 1, sz / 2, x1, y1);
        }

        static void drawLine(double x0, double y0, double x1, double y1)
        {
            std::cout << "Draw line from (" << x0 << ", "
            << y0 << ") to (" << x1 << ", " << y1 << ")"
            << std::endl;
        }
};
int main(int argc, char* argv[])
{
    int n = 0;
    std::cout << "Input desired N value: ";
    std::cin >> n;
    
    Htree::draw(n, 0.5, 0.5, 0.5);
    return 0;
}