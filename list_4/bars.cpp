#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int b_length, amount;
int p_bars[21];

bool checkSubsets(int start, int sum)
{
	if(sum == b_length)
		return true;
	if(amount <= start or sum > b_length)
		return false;

	bool possible = false;
	
	for(int i = start; i < amount and !possible; ++i)
		possible = checkSubsets(i + 1, p_bars[i] + sum);

	return possible;
}

int main()
{
    int t;
    cin >> t;
    
    while (t, t--) {
        cin >> b_length >> amount;

        for(int i = 0; i < amount; i++) {
            cin >> p_bars[i];
        }
        
        if(checkSubsets(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
    }

    return 0;
}
