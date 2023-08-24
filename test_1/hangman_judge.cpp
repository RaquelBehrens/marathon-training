#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int c;
    cin >> c;
    
    while(c != -1) {
        string solution;
        string attempts;

        cin >> solution >> attempts;

        bool all_found = false;
        int body = 0;

        for (char a : attempts) {
            if (solution.empty() && body < 7) {
                all_found = true;
                break;
            }
            if (strchr(solution.c_str(), a) != nullptr) {
                solution.erase(std::remove_if(solution.begin(), solution.end(),
                                   [a](char c) { return c == a; }),
                   solution.end());
            } else {
                body += 1;
            }
        }

        if (solution.empty() && body < 7) {
            all_found = true;
        }

        printf("Round %d\n", c);
        if (all_found) { 
            printf("You win.\n");

        } else {
            if (body >= 7) {
                printf("You lose.\n");
            } else {
                printf("You chickened out.\n");
            }
        }

        cin >> c;
    }

    return 0;
}