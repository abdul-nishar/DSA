#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> sortArrByDiffArr(vector<int>& arr1, int N, vector<int>& arr2, int M) {
    vector<int> result;

    map<int,int> numMap;

    for(int i=0;i<N;i++) numMap[arr1[i]]++;

    for(int i=0;i<M;i++){
        if(numMap.count(arr2[i])){
            int temp = numMap[arr2[i]];
            while(temp > 0) {result.push_back(arr2[i]);temp--;}
            numMap.erase(arr2[i]);
        }
    }

    for(auto value : numMap){
        int temp = value.second;
        while(temp > 0) {result.push_back(value.first);temp--;}
    }
    
    return result;
}

int main(){
    vector<int> arr1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> arr2 = {2, 1, 8, 3};
    vector<int> result = sortArrByDiffArr(arr1,arr1.size(), arr2, arr2.size());
    for(auto value : result) cout << value << " ";
    return 0;
}