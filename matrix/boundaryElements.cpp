#include <iostream>
#include <vector>
using namespace std;

vector<int> boundaryElements(const vector<vector<int> >& matrix) {
    vector<int> result;

    for(int i = 0; i < matrix.size(); i++){
        if(i == 0) for(int j = 0; j < matrix[i].size(); j++) result.push_back(matrix[i][j]);
        else if(i == matrix.size() - 1) for(int j = matrix[i].size() - 1; j >= 0; j--) result.push_back(matrix[i][j]);
        else result.push_back(matrix[i][matrix[i].size() - 1]);
    }

    for(int i = matrix.size() - 2; i > 0;i--) result.push_back(matrix[i][0]);

    return result;
}

int main(){
    vector<vector <int>> arr1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> result = boundaryElements(arr1);
    for(int i = 0; i < result.size();i++) cout << result[i] << " ";
    return 0;
}