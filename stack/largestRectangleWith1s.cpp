#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxRectArea2(vector<int> arr){
    stack<int> prevIdxStack;
    int n = arr.size();
    int maxArea = 0;

    for(int i=0; i<=n;i++){
        while(!prevIdxStack.empty() && (i==n || arr[prevIdxStack.top()] >= arr[i])){
            int height = arr[prevIdxStack.top()];
            prevIdxStack.pop();
            int width = prevIdxStack.empty() ? i : i - prevIdxStack.top() - 1;
            maxArea = max(maxArea, height*width);
        }
        prevIdxStack.push(i);
    }

    return maxArea;
}

void largestRectangleWith1s(vector<vector<int>> matrix) {
    int maxArea = maxRectArea2(matrix[0]);

    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++) {
            if(matrix[i][j] != 0) matrix[i][j] += matrix[i-1][j];
        }
        int curMaxArea = maxRectArea2(matrix[i]);
        maxArea = max(curMaxArea, maxArea);
    }

    cout << "Maximum rectangle Area : " << maxArea << endl;
}

int main(){
    vector<vector<int>> binMat = {{1,1,1}};
    largestRectangleWith1s(binMat);
    return 0;
}