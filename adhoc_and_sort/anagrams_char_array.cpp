#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool lexicographic(const string& first, const string& second)
{
    return lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
}

const vector<int> letterBase(128, 0);

vector<int> GetLetterCounts(string word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (*iter != ' ')
            ++letterCounts[*iter];
    }
    
    return letterCounts;
}

bool isEqual(const vector<int>& first, const vector<int>& second)
{
    for (int i = 0; i < 128; ++i)
        if (first[i] != second[i])
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
        vector<string> anagrams;
        int i;

        while (getline(cin, word) && word != "")
        {
            anagrams.push_back(word);
        }

        sort(anagrams.begin(), anagrams.end(), lexicographic);

        vector<vector<int> > letterCounts(anagrams.size());
        
        for (int i = 0; i < anagrams.size(); ++i)
            letterCounts[i] = GetLetterCounts(anagrams[i]);

        cout << separator;
        separator = "\n";

        bool found_anagrams;
        for (int k = 0; k < anagrams.size(); k++) {
            for (int l = k+1; l < anagrams.size(); l++) {
                if (isEqual(letterCounts[k], letterCounts[l])) {
                    cout << anagrams[k] << " = " << anagrams[l] << '\n';
                }
                
            }
        }
    }

    return 0;
}
