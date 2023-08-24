#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--) {
        int isOdd[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        bool showedUp[12] = {};
        char weight;
        char preference_odd = 'Z';

        for(int testCases = 0; testCases < 3; ++testCases) {
            string coins_right;
            string coins_left;
            string word;
            cin >> coins_right >> coins_left >> word;

            char letter = word[0];
            if (letter == 'e') {
                for (char coin : coins_right+coins_left) {
                    showedUp[coin - 'A'] = true;
                    isOdd[coin - 'A'] = -1;
                }
            } else {
                for (char coin : coins_right+coins_left) {
                    if (isOdd[coin-'A'] >= 0) {
                        if (isOdd[coin - 'A'] == 1) {
                            preference_odd = coin;
                        } 
                        isOdd[coin-'A']++;
                        showedUp[coin - 'A'] = true;
                    }
                }
                weight = letter;
            }
            
        }

        if (preference_odd != 'Z') {
            if (weight == 'd') {                    
                printf("%c is the counterfeit coin and it is heavy.\n", preference_odd);
            } else {
                printf("%c is the counterfeit coin and it is light.\n", preference_odd);
            }
            return 0;
        }

        for (int i = 0; i < 12; i++) {
            if (isOdd[i] > 0 && showedUp[i]){
                char letter = static_cast<char>('A' + i);
                if (weight == 'd') {                    
                    printf("%c is the counterfeit coin and it is heavy.\n", letter);
                } else {
                    printf("%c is the counterfeit coin and it is light.\n", letter);
                }
                return 0;
            }
        }
                
    }

    return 0;
}