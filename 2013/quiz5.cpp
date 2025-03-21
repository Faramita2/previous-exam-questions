#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void backtracking(vector<vector<int>>& board, int startIndex, int& count) {
    if (startIndex == board.size()) {
        count++;
        return;
    }
    for (int j = 0; j < board.size(); j++) {
        if (isSafe(board, startIndex, j)) {
            board[startIndex][j] = 1;
            backtracking(board, startIndex + 1, count);
            board[startIndex][j] = 0;
        }
    }
}

int main() {
    ifstream inputFile("5.in");
    ofstream outputFile("5.out");

    int n;
    inputFile >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int start = 0;
    int count = 0;
    backtracking(board, start, count);
    outputFile << count;

    return 0;
}