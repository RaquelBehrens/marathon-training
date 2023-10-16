#include <bits/stdc++.h>


using namespace std;

int main() {
	int n;

	while (cin >> n, n) {
		vector<int> arr;

		for(int i = 0; i < n; i++){
			int m;
			cin >> m;
			if(m > 0) arr.push_back(m);
		}

		int size = arr.size();
		if (size==0) cout << "0\n";

		else {
			for(int i = 0; i < size; i++){
				cout << arr.at(i);
				if (i != size-1) cout << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}