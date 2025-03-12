#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> board;

int res = 0;

bool isSafe(int row, int col)
{
    // 同列
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 1)
            return false;
    }
    // 左上角
    for (int j = col - 1, i = row - 1; j >= 0 && i >= 0; j--, i--) {
        if (board[i][j] == 1)
            return false;
    }
    // 右上角
    for (int j = col + 1, i = row - 1; j < board.size() && i >= 0; j++, i--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void backtracking(int rowNum)
{
    if (rowNum == board.size())
        res++;

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(rowNum, col)) {
            board[rowNum][col] = 1;
            backtracking(rowNum + 1);
            board[rowNum][col] = 0;
        }
    }
}

int main()
{
    ifstream inputFile("5.in");
    ofstream outputFile("5.out");
    int      n;
    inputFile >> n;
    cout << "n: " << n << endl;
    board = vector(n, vector<int>(n, 0));
    backtracking(0);

    cout << "res: " << res << endl;
    outputFile << res;

    return 0;
}