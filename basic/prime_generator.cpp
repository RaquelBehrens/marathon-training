#include <stdio.h>
#include <cmath>
#include <vector>

int* findNumbersList(int best) {
    int* possibilities = new int[best-2];
    for (int i = 2; i < best; i++) {
        possibilities[i-2] = i;
    }
    return possibilities;
}

int* removeZeros(const int* auxList, int size, int lowest) {
    int* noZeros = new int[size];
    int newSize = 0;

    for (int i = 0; i < size; ++i) {
        if (auxList[i] && auxList[i] > lowest) {
            noZeros[newSize++] = auxList[i];
        }
    }

    return noZeros;
}

int* primesBetween(int lowest, int highest) {
    int* auxList = findNumbersList(highest);
    int limit = static_cast<int>(std::sqrt(highest));

    for (int i = 0; i < limit; i++) {
        if (!auxList[i]) {
            continue;
        }

        for (int j = i + 1; j < highest - 2; j++) {
            if (auxList[j] && (!(auxList[j] % auxList[i]))) {
                auxList[j] = 0;
            }
        }
    }

    return removeZeros(auxList, highest - 2, lowest);
}

int main() {
    int quantity;
    scanf("%d ", &quantity);

    for(int i = 0; i < quantity; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int* primos = primesBetween(a-1, b+1);

        int f = primos[0];
        int index = 1;

        while (f > 0) {
            printf("%d\n", f);
            f = primos[index];
            index++;
        } 

        if (i != quantity-1) {
            printf("\n");
        }
    }
    
    return 0;
}