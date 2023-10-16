#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>

struct Card {
    char number;
    char value;
};

int main() {
    int n, pos, current, Y;
    
    char cards[52][3];
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i)
    {
        Y = 0;
        pos = 52 - 25;
        
        for (int i = 0; i < 52; ++i)
            scanf("%s", cards[i]);
        
        printf("Case %d: %s\n", i, cards[32]);

    }

    /*int n;
    scanf("%d\n", &n);

    int y = 0;
    std::vector<Card> cardList;
    int converted_number;
    char number;
    char suit;
    char teste;

    int size = 52;
    int sizeRemoval = 26;

    for(int i = 0; i < n; i++) {
        cardList.clear();
        y = 0;

        for(int j = 0; j < 52; j++) {
            scanf("%c%c%c", &number, &suit, &teste);
            cardList.push_back({number, suit});
        }

        int top = 0;
        int remove = 0;
        int value = 0;
        char element = '0';

        for(int j = 0; j < 3; j++){
            top = size - sizeRemoval - j - remove;
            element = cardList[top].number;                
            value = std::isalpha(element) ? 10 : element - '0';
            cardList.erase(cardList.begin() + (top));
            y += value;
            remove = 10-value;
            cardList.erase(cardList.begin() + (top-(remove)), cardList.begin() + (top));
        }

        printf("Case %d: %c%c\n", i+1, cardList[y-1].number, cardList[y-1].value);
    }
    */
    return 0;
}
