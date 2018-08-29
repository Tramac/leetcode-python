#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int rows = matrix.size(), cols = matrix[0].size();
    bool res = true;
    int row = 0, col = cols - 1;
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) break;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    if (row >= rows || col < 0) res = false;
    return res;
}

int main() {
    vector<vector<int>> matrix(1, vector<int>(1, -5));
    bool res = searchMatrix(matrix, -2);
    return 0;
}
