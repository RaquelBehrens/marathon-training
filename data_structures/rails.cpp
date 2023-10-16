#include <iostream>
#include <stack> 

using namespace std;

int main ()
{
    int N;
    while (cin >> N, N) {
        int coach;
        stack<int> s;

        while (cin >> coach, coach) {
            while (!s.empty())
                s.pop();
            
            int numAdded = 1;
            bool isPossible = true;
            
            s.push(numAdded++);
            
            while (s.top() != coach)
                s.push(numAdded++);
            
            isPossible = (s.top() == coach);
            s.pop();

            for(int i = 1; i < N; i++) {
                cin >> coach;
                
                if (isPossible)
                {
                    if (s.empty())
                        s.push(numAdded++);
                    
                    while (s.top() != coach && numAdded <= N)
                        s.push(numAdded++);
                    
                    isPossible = (s.top() == coach);
                    
                    s.pop();
                }
            }

            cout << (isPossible ? "Yes\n" : "No\n");
        }

        cout << '\n';
    }

    return 0;
}