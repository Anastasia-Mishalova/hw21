// hw21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

using namespace std;

// Размсестить ранее написанные классы по работе с математическими примитивами в пространство имен

namespace newNS
{
    class Root
    {
    public:
        virtual void  rootsEquation() = 0;
    };

    class Square : public Root
    {
    private:
        double a, b, c, x1, x2, d;

    public:
        Square(double a, double b, double c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void rootsEquation()
        {
            d = b * b - 4 * a * c;

            if (d > 0)
            {
                x1 = ((-b) + sqrt(d)) / (2 * a);
                x2 = ((-b) - sqrt(d)) / (2 * a);
                cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;
            }
            else if (d == 0.0)
            {
                x1 = -(b / (2 * a));
                cout << "x1 = x2 = " << x1 << "\n";
            }
            else
            {
                cout << "Корней нет\n";
            }
        }
    };

    class Linear : public Root
    {
    private:
        double a;
        double b;
    public:
        Linear(double a, double b)
        {
            this->a = a;
            this->b = b;
        }
        void rootsEquation()
        {
            if (a == 0.0)
            {
                cout << "Корней нет!\n";
            }
            else
            {
                double x3;
                x3 = -b / a;
                cout << "x = " << x3 << endl;
            }
        }
    };
}

void main()
{
    setlocale(LC_ALL, "ru");

    newNS::Root* square = new newNS::Square(1, 2, -3);
    newNS::Root* line = new newNS::Linear(5, 40);

    square->rootsEquation();
    line->rootsEquation();
    }