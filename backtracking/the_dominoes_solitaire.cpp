#include <iostream>
#include <vector>

struct Piece {
    int left;
    int right;
};

void swapPieces(std::vector<Piece>& board, int i, int j) {
    std::swap(board[i].left, board[j].left);
    std::swap(board[i].right, board[j].right);
}

bool checkRecursive(int left, int right, std::vector<Piece>& board, int piece, int pre_left, int n) {
    if (piece == n) {
        int pre_piece = piece - 1;
        return (board[pre_piece].left == pre_left && board[pre_piece].right == right) ||
               (board[pre_piece].left == right && board[pre_piece].right == pre_left);
    } else {
        for (int i = piece; i < board.size(); i++) {
            swapPieces(board, piece, i);
            
            if (left == board[piece].left) {
                if (checkRecursive(board[piece].right, right, board, piece + 1, left, n)) {
                    return true;
                }
            } else if (left == board[piece].right) {
                if (checkRecursive(board[piece].left, right, board, piece + 1, left, n)) {
                    return true;
                }
            }
            
            swapPieces(board, piece, i);
        }
    }
    return false;
}

bool check(int left, int right, std::vector<Piece>& board, int n) {
    return checkRecursive(left, right, board, 0, left, n);
}

int main() {
    int n;
    while (std::cin >> n, n) {
        int m, ignore, left, right;
        std::cin >> m;
        std::cin >> ignore >> left;
        std::cin >> right >> ignore;

        std::vector<Piece> board(m);

        for (int i = 0; i < m; i++) {
            std::cin >> board[i].left >> board[i].right;
        }

        if (check(left, right, board, n)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
