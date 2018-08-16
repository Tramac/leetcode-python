#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int maxdist = m + n;
    queue<pair<int, int> > q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                q.push(make_pair(i, j));
            }
            else {
                matrix[i][j] = maxdist;
            }
        }
    }
    int delta[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int k = 0; k < 4; ++k) {
            int x1 = x + delta[k][0], y1 = y + delta[k][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                if (matrix[x1][y1] == maxdist) {
                    matrix[x1][y1] = min(matrix[x1][y1], matrix[x][y] + 1);
                    q.push(make_pair(x1, y1));
                }
            }
        }
    }
    return matrix;
}
