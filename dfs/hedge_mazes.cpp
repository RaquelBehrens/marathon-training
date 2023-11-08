#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int r, c, q, a, b;

vector<int> corridors[maxn];
int isImpossible = false;

bool search(int s, int t) {
    if(isImpossible) {
		return false;
	}
    int next = s+1;
    if(next == t && std::find(corridors[s].begin(), corridors[s].end(), next) != corridors[s].end()) {
        return true;
    }    
    if(std::find(corridors[s].begin(), corridors[s].end(), next) != corridors[s].end()) {
        search(next, t);
    }
    return false;
}

int main() {
	while (cin >> r >> c >> q, r || c || q) {
        for (int i = 0; i < r; i++)
			corridors[i].clear();
        

		for (int i = 0; i < c; i++) {
            cin >> a >> b;
			corridors[a-1].push_back(b-1);
            corridors[b-1].push_back(a-1);
		}
        
        int s, t;
        for (int j = 0; j < q; j++) {
            cin >> s >> t;
            isImpossible = false;
            cout << (search(s-1, t-1) ? "Y" : "N") << endl;
		}

        cout << "-" << endl;
	}
	return 0;
}