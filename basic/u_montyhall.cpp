#include <stdio.h>

int main() {
    int quantity;
    scanf("%d ", &quantity);

    int timesWon = 0;

    for(int i = 0; i < quantity; i++) {
        int car;
        scanf("%d", &car);

        int doorChosen = 1;

        /*
        if (car == 2) {
            doorChosen = 2;
        } else if (car == 3) {
            doorChosen = 3;
        } else {
            doorChosen = 3;
        }
        */

        int doorChosen = 3;  // Default value for any case other than 2 or 3
        if (car == 2 || car == 3) {
            doorChosen = car;
        }
        

        // if car is behind door 1: reveals door 1 or 2, does not matter to wich the user will change
        // if car is behind door 2: reveals door 3, therefore to the person, the car is behind 1 or 2, changes to 2
        // if car is behind door 3: reveals door 2, therefore to the person, the car is behind 1 or 3, changes to 3

        if (doorChosen == car) {
            timesWon++;
        }
    }

    printf("%d\n", timesWon);
    
    return 0;
}
