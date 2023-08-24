#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--) {
        bool isOdd[12] = {true, true, true, true, true, true, true, true, true, true, true, true};
        bool showedUp[12] = {};
        char weight;

        for(int testCases = 0; testCases < 3; ++testCases) {
            string coins_right;
            string coins_left;
            string word;
            cin >> coins_right >> coins_left >> word;

            char letter = word[0];
            if (letter == 'e') {
                for (char coin : coins_right+coins_left) {
                    showedUp[coin - 'A'] = true;
                    isOdd[coin - 'A'] = false;
                }
            } else {
                for (char coin : coins_right+coins_left) {
                    showedUp[coin - 'A'] = true;
                    weight = letter;
                }
            }
            
        }

        for (int i = 0; i < 12; i++) {
            if (isOdd[i] && showedUp[i]){
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