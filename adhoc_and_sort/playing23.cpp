#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int jf, js;
    cin >> jf >> js;

    int mf, ms;
    cin >> mf >> ms;

    int cards[14] = {};
    cards[jf]++;
    cards[mf]++;
    cards[js]++;
    cards[ms]++;

    if (jf > 10) {
        jf = 10;
    }

    if (mf > 10) {
        mf = 10;
    }

    if (js > 10) {
        js = 10;
    }

    if (ms > 10) {
        ms = 10;
    }
    
    int john = 23 - jf - js;
    int mary = 23 - mf - ms;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cards[c]++;
        
        if (c > 10) {
            c = 10;
        }

        john -= c;
        mary -= c;
    }

    int answer = john + 1;

    if (mary > 10 && john + 1 > 10) {
        cout << -1 << '\n';
        return 0;
    }

    if (mary < 0) {
        cout << -1 << '\n';
        return 0;
    }

    while (answer < mary) {
        if (cards[answer] < 4) {
            if (answer > 10) {
                cout << 10 << '\n';
            } else {
                cout << answer << '\n';
            }
            return 0;
        }
        answer++;
    }

    //aqui tem que pensar que mary pode ser 10 e todas as cartas 10 já se foram
    if (mary > 0 && cards[mary] < 4) {
        cout << mary << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}

