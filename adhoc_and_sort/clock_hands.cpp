#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    cout << fixed << setprecision(3);

    double h, m;
    char temp;

    scanf("%lf:%lf",&h, &m);

    while (h)
    {
        h += m / 60.0;

        double minutes = m * 6.0;
        double hours = h * 30.0;

        double angle = std::round(hours - minutes);

        if (angle > 180) {
            angle = 360 - angle;
        }

        cout << angle << '\n';
        cin >> h >> temp >> m;
    }
    return 0;
}