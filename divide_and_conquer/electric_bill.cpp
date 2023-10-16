#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int priceToConsumption(int price) {
    int cons = 0;
    cons += min(max(0, price/2), 100); price -= 2*100;
    cons += min(max(0, price/3), 9900); price -= 3*9900;
    cons += min(max(0, price/5), 990000); price -= 5*990000;
    cons += max(0, price/7);
    return cons;
}

int consumptionToPrice(int cons) {
    int price = 0;
    price += min(max(0, cons*2), 2*100); cons -= 100;
    price += min(max(0, cons*3), 3*9900); cons -= 9900;
    price += min(max(0, cons*5), 5*990000); cons -= 990000;
    price += max(0, cons*7);
    return price;
}

int main()
{
    int A, B;
    while (cin >> A >> B, A|B) {
        int total = priceToConsumption(A);
        
        int l = 0;
        int r = total;
        int answer = 0;

        while(l < r) {
            int mid = (l+r)/2;
            int diff = consumptionToPrice(total-mid)-consumptionToPrice(mid);
            if (diff > B) {
                l = mid;
            } else if (diff < B) {
                r = mid;
            } else { 
                answer = mid; 
                break; 
            }
        }
        
        cout << consumptionToPrice(answer) << endl;      
    }

    return 0;
}
