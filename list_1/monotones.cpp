#include <stdio.h>

int main() {
    int quantity;
    scanf("%d ", &quantity);

    char word[quantity+1];
    scanf("%s", word);

    char p, pp;
    int counter = 0;
    int result = 0;
    for(int i = 0; i < quantity; i++) {
        if (word[i] == 'a') {
            counter++;
        } else {
            if (counter > 1) {
                result = result + counter;
            }
            counter = 0;
        }
    }
    if (counter > 1) {
        result = result + counter;
    }      
    printf("%d\n", result); 
    
    return 0;
}
