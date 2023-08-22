#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", n);
    printf("");

    for(int i = 0; i < n; i++) {
        string anagrams[100];

        for(int i = 0; i < 100; i++) {
            string word;
            getline(cin, word);

            word.erase(word.find_last_not_of(" \t\n\r\f\v") + 1);
            if (word.empty()) {
                break;
            }

            sort(word.begin(), word.end());
            anagrams[i] = word;

            
        }
    }



    return 0;
}
