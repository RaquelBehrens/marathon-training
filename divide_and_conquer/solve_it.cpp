#include <bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u;

double f(double x) {
	return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}


int main()
{
    while (cin >> p >> q >> r >> s >> t >> u) {
        double a = 0.0; // Limite esquerdo do intervalo
        double b = 1.0; // Limite direito do intervalo
        double tolerancia = 1e-9; // Tolerância para a precisão desejada

        while ((b - a) >= tolerancia) {
            double c = (a + b) / 2.0; // Encontre o ponto médio do intervalo

            if (f(c) < 0) {
                b = c; // Atualize o intervalo [a, c]
            } else {
                a = c; // Atualize o intervalo [c, b]
            }
        }

        if (abs(f((a + b) / 2)) <= 1e-4)
            cout << setprecision(4)
                 << fixed
                 << (a + b) / 2.0 
                 << endl;
        else
            cout << "No solution" << endl;
      
    }

    return 0;
}
