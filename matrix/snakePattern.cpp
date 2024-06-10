#include <iostream>
#include <vector>
using namespace std;

void snakePattern(const vector<vector<int> >& matrix) {
    bool front  = true;
    for(int i = 0; i < matrix.size(); i++){
        if(front){
            for(int j = 0; j < matrix[i].size(); j++) cout << matrix[i][j] << " ";
            front = false;
        }else {
            for(int j = matrix[i].size() - 1; j >= 0 ; j--) cout << matrix[i][j] << " ";
            front = true;
        }
    }
}

int main(){
    vector<vector <int>> arr1 = {{45,48,54},{21,89,87},{70,78,15}};
    snakePattern(arr1);
    return 0;
}