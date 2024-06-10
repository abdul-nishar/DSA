#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTransversal(vector<vector<int> >& matrix, int r, int c) {
    vector<int> result;
    if (matrix.empty() || r == 0 || c == 0) {
        return result;
    }

    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        ++top;

        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        --right;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            --bottom;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
        }
    }

    return result;
}

int main(){
    vector<vector <int>> arr1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = 3, column = 4;
    vector<int> result = spiralTransversal(arr1, row, column);
    for(int i=0;i<row*column;i++) cout << result[i] << " ";
    return 0;
}