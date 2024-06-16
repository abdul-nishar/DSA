#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> sortingArrByFreq(vector<int>& arr) {
    vector<int> result;
    unordered_map<int,int> numMap;

    for(int i = 0; i < arr.size(); i++) numMap[arr[i]]++;

    vector<vector<int>> storage;

    for(auto pair : numMap) storage.push_back({pair.first,pair.second});

    sort(storage.begin(), storage.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[1]==b[1]) return a[0] < b[0];
        return a[1] > b[1];
    });

    for(int i=0;i<storage.size();i++){
        int temp = storage[i][1];
        while(temp>0) {result.push_back(storage[i][0]);temp--;}
    }

    return result;
}

int main(){
    vector<int> arr1 = {5,5,4,4,8,9,9,9};
    vector<int> result = sortingArrByFreq(arr1);
    for(auto value : result) cout << value << " ";
    return 0;
}