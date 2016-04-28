#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
const double eps = pow(10, -7);
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    if (fabs(d) < eps)
    {
        double x1 = -b / (2 * a);
        if (fabs(x1) < eps)
            x1 = 0.0;
        cout << fixed << setprecision(5) << "x1=x2=" << x1 << endl;
        
    }
    else if (d > eps)
    {
        double x1 = (-b + sqrt(d)) / (2 * a), x2 = (-b - sqrt(d)) / (2 * a);
        if (fabs(x1) < eps)
            x1 = 0.0;
        if (fabs(x2) < eps)
            x2 = 0.0;
        cout << fixed << setprecision(5) << "x1=" << x1 << ";x2=" << x2 << endl;
    }
    else if (d < -eps)
    {
        double x1 = -b / (2 * a);
        if (fabs(x1) < eps)
            x1 = 0.0;
        double y = sqrt(-d) / (2 * a);
        if (fabs(y) < eps)
            y = 0.0;
        cout << fixed << setprecision(5) << "x1=" << x1 << '+' << sqrt(-d) / (2 * a) << "i;x2=" << x1 << '-' << sqrt(-d) / (2 * a) << 'i' << endl;
    }
    system("pause");
    return 0;
}