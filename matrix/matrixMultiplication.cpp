#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        vector<vector<int>> result;
        for(int i=0;i<A.size();i++){
            if(A[i].size() != B.size()) return {{-1}};
            else {
                vector<int> vec;
                for(int j=0;j<B[0].size();j++){
                    int sum = 0;
                    for(int k=0;k<B.size();k++) sum+=A[i][k]*B[k][j];
                    vec.push_back(sum);
                }
                result.push_back(vec);
            }
        }
        
        return result;
    }

int main(){
   vector<vector<int>> arr1 = {{35,1},{70,25},{79,59},{63,65},{6,46},{82,28},{62,92}};
    vector<vector<int>> arr2 = {{43,28,37,92,5,3,54},{93,83,22,17,19,96,48}};

   vector<vector<int>> result = multiplyMatrix(arr1, arr2);

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++) cout << result[i][j] << " ";cout <<endl;
    }
    return 0;
}