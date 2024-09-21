#include <iostream>
#include <vector>

using namespace std;

void dfsTraversal(vector<vector<int>>& image, vector<vector<int>>& ans, int row, int col, int delrow[], int delcol[], int newColor, int curColor){

    int n = image.size();
    int m = image[0].size();

    ans[row][col] = newColor;
    
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == curColor && ans[nrow][ncol] != newColor) dfsTraversal(image, ans, nrow, ncol, delrow, delcol, newColor, curColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int curColor = image[sr][sc];
    
    if (curColor == newColor) return image;
    
    vector<vector<int>> ans = image;
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    
    dfsTraversal(image, ans, sr, sc, delrow, delcol, newColor, curColor);
    
    return ans;
}