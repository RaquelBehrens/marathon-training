#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>


int main() {
    std::string inputLine;
    std::getline(std::cin, inputLine);

    int gl = 0;
    int pl = 0;
    int gr = 0;
    int pr = 0;
    int turn = 0;
    
    for (std::size_t i = 0; i < inputLine.size(); ++i) {
        char c = inputLine[i];

        if (c == 'S') {
            if (turn == 0) {
                pl += 1;
                turn = 0;
            } else {
                pr += 1;
                turn = 1;
            }
        } else if (c == 'R') {
            if (turn == 0) {
                pr += 1;
                turn = 1;
            } else {
                pl += 1;
                turn = 0;
            }
        } else if (c == 'Q') {
            if (i < inputLine.size() - 1) {
                if (turn == 1) {
                    printf("%d (%d) - %d (%d*)\n", gl, pl, gr, pr);
                } else {
                    printf("%d (%d*) - %d (%d)\n", gl, pl, gr, pr);
                }
            } else {
                if (gl-gr > 0) {
                    printf("%d (winner) - %d\n", gl, gr);
                } else {
                    printf("%d - %d (winner)\n", gl, gr);
                }
                
            }
        }

        int diff = pr - pl;

        if (pr == 10) {
            gr += 1;
            pl = 0;
            pr = 0;
        } else if (pl == 10) {
            gl += 1;
            pl = 0;
            pr = 0;
        } else {
            if ((pr >= 5 || pl >= 5) && std::abs(diff) >= 2) {
                if (diff < 0) {
                    gl += 1;
                } else {
                    gr += 1;
                }
                pl = 0;
                pr = 0;
            }
        }
    }


    return 0;
}
