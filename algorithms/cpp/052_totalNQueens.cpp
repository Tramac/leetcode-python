#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int row, vector<bool>& cols, vector<bool>& rightup, vector<bool>& leftup, int n, int& count) {
    if (row == n) count++;
    for (int col = 0; col < n; col++) {
        int id1 = col - row + n;
        int id2 = col + row;
        if (cols[col] || rightup[id1] || leftup[id2]) continue;
        cols[col] = true, rightup[id1] = true, leftup[id2] = true;
        backtracking(row + 1, cols, rightup, leftup, n, count);
        cols[col] = false, rightup[id1] = false, leftup[id2] = false;
    }
}

int totalNQueens(int n) {
    int count = 0;
    vector<bool> cols(n, false);
    vector<bool> rightup(2 * n, false);
    vector<bool> leftup(2 * n, false);
    backtracking(0, cols, rightup, leftup, n, count);
    return count;
}

int main()
{
    int res = totalNQueens(8);
    return 0;
}
