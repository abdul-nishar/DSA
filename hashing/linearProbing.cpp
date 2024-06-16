#include <iostream>
#include <vector>
using namespace std;

vector<int> linearProbing(vector<int>& A) {
    int hashSize = A.size();
    vector<int> result(hashSize, -1);

    for(int i = 0; i < hashSize; i++){
        int index = A[i] % hashSize;
        if(result[index]==-1) result[index] = A[i];
        else {
            int temp = (index + 1)%hashSize;
            while(temp != index){
                if(result[temp] != -1) temp = (temp+1) % hashSize;
                else {result[temp] = A[i];break;}
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr1 = {45,6,56,32,424,97,75,98};
    vector<int> result = linearProbing(arr1);
    for(auto value : result) cout << value << " ";
    return 0;
}