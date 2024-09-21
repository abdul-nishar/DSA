#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

vector<double> median(int arr[], int n){
    vector<double> result;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(arr[0]);
    result.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(maxHeap.size() > minHeap.size()){
            if(arr[i] < maxHeap.top()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }else minHeap.push(arr[i]);
        }else maxHeap.push(arr[i]);

        if(i % 2 != 0) result.push_back((double)(maxHeap.top() + minHeap.top()) / 2);
        else result.push_back(maxHeap.top());
    }

    return result;
}

int main(){
    int nums[] = {12,15,10,5,8,7,16};

    vector<double> result = median(nums,7);

    for(auto val : result) cout << val << " ";

    return 0;
}