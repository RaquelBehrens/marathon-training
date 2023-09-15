// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

using namespace std;

int main ()
{
    int size;
    queue<int> myqueue;

    while (cin >> size, size) {
        for(int i = 1; i <= size; i++) {
            myqueue.push(i);
        }
        cout << "Discarded cards:";

        string sep = " ";
        while(myqueue.size() > 1) {
            cout << sep << myqueue.front();
            sep = ", ";
            myqueue.pop();
            myqueue.push(myqueue.front());
            myqueue.pop();
        }

        cout << "\nRemaining card: " << myqueue.front() << '\n';       
        myqueue.pop(); 
    }

    return 0;
}