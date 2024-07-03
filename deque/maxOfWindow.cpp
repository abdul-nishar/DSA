#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxInWindow(int arr[],int n, int k){
    deque<int> deq;
    vector<int> result;

    int index = 0;
    
    for(; index < k; index++){
        while(!deq.empty() && arr[deq.back()] < arr[index]) deq.pop_back(); 
        deq.push_back(index);
    }

    result.push_back(arr[deq.front()]);

    for(; index<n; index++){

        // Using the current index, we find whether the front index is out of the window or not
        while(!deq.empty() && index - deq.front() == k) deq.pop_front();

        // Removing the elements at the front which are smaller than the current element
        while(!deq.empty() && arr[deq.back()] < arr[index]) deq.pop_back(); 
        deq.push_back(index);

        result.push_back(arr[deq.front()]);
    }

    return result;
}

int main(){
    int numArr[] = {20,30,40,10,60};
    vector<int> result = maxInWindow(numArr, 5, 3);

    for(auto value : result) cout << value << " ";
    return 0;
}