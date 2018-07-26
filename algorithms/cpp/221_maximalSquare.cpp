#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<char> >& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int> > dp(rows, vector<int>(cols, 0));
    int maxsize = 0;
    for(int i = 0; i < rows; ++i)
    {
        dp[i][0] = matrix[i][0] - '0';
        maxsize = max(maxsize, dp[i][0]);
    }
    for(int i = 0; i < cols; ++i)
    {
        dp[0][i] = matrix[0][i] - '0';
        maxsize = max(maxsize, dp[0][i]);
    }
    for(int i = 1; i < rows; ++i)
    {
        for(int j = 1; j < cols; ++j)
        {
            if(matrix[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxsize = max(maxsize, dp[i][j]);
            }
        }
    }
    return maxsize * maxsize;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<char> num;
    vector<vector<char> > matrix;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            char tmp;
            cin >> tmp;
            num.push_back(tmp);
        }
        matrix.push_back(num);
        num.clear();
    }
    int res = maximalSquare(matrix);
    return 0;
}

