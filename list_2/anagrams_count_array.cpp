#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NO_OF_CHARS 256

string removeWhitespaces(const string& input) {
    string result;
    for (char c : input) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}

bool areAnagram(const string& first, const string& second) {
    // Create a count array and initialize all values as 0
    int count[NO_OF_CHARS] = { 0 };
    int i;
   
    // For each character in input strings, increment count
    // in the corresponding count array
    for (i = 0; first[i] && second[i]; i++) {
        count[first[i]]++;
        count[second[i]]--;
    }
   
    // If both strings are of different length. Removing
    // this condition will make the program fail for strings
    // like "aaca" and "aca"
    if (first[i] || second[i])
        return false;
 
    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string word;
    getline(cin, word);

    string separator = "";    
    for(int j = 0; j < n; j++) {
        string anagrams_without_spaces[100];
        string anagrams[100];
        int i;

        for(i = 0; i < 100; i++) {
            string word;
            getline(cin, word);
            anagrams[i] = word;
            
            if (word.empty()) {
                break;
            }

            string word_without_spaces = removeWhitespaces(word);
            anagrams_without_spaces[i] = word_without_spaces;
        }

        cout << separator;
        separator = "\n";

        bool found_anagrams;
        for (int k = 0; k < i; k++) {
            for (int l = k+1; l < i; l++) {
                if (areAnagram(anagrams_without_spaces[k], anagrams_without_spaces[l])) {
                    cout << anagrams[k] << " = " << anagrams[l] << '\n';
                    found_anagrams = true;
                }
            }
        }
    }

    return 0;
}
