#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> slidingWindowMax(int arr[], int n, int k){
    vector<int> result;
    queue<int> minQueue;

    int noOfWindows = n - k + 1;

    for(int i=0;i<k;i++) {
        if(minQueue.empty()) minQueue.push(arr[i]);
        else {
            if(arr[i]>minQueue.back()) minQueue.push(arr[i]);
        }
    }

    result.push_back(minQueue.back());

    for(int i=k;i<n;i++){
        minQueue.pop();
        if(minQueue.back() < arr[i]) minQueue.push(arr[i]);
        result.push_back(minQueue.back());
    }

    return result;
}

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> result = slidingWindowMax(arr, sizeof(arr)/ sizeof(arr[0]), 3);
    for(auto value : result) cout << value << " ";
    cout << endl;
    return 0;
}