
#include <iostream>     // std::cout
#include <queue>        // std::priority_queue

using namespace std;

int main () {
    int size;
    while (cin >> size, size > 0) {
        priority_queue<int,vector<int>,greater<int> > queue;
        for(int i = 0; i < size; i++) {
            int element;
            cin >> element;
            queue.push(element);
        }

        int count = 0;
        int cost = 0;

        while(count < size - 1) {
            int temp = queue.top();
            queue.pop();
            temp += queue.top();
            queue.pop();

            queue.push(temp);
            cost += temp;
            count++;
        }

        printf("%d\n", cost);
    }

  return 0;
}
