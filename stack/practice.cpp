#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> prevSmallerElement(int arr[], int n){
    vector<int> result(n);
    stack<int> indexStack;

    for(int i=0;i<n;i++){
        while(!indexStack.empty() && arr[indexStack.top()] >= arr[i]){
            indexStack.pop();
        }
        result[i] = indexStack.empty() ? -1 : indexStack.top();
        indexStack.push(i);
    }

    return result;
}

vector<int> nextSmallerElement(int arr[], int n){
    vector<int> result(n);
    stack<int> indexStack;

    for(int i=n-1;i>=0;i--){
        while(!indexStack.empty() && arr[indexStack.top()] >= arr[i]){
            indexStack.pop();
        }
        result[i] = indexStack.empty() ? n : indexStack.top();
        indexStack.push(i);
    }

    return result;
}

vector<int> maxOfMin(int arr[], int n){
    vector<int> result(n, INT_MIN);
    vector<int> prevS = prevSmallerElement(arr, n);
    vector<int> nextS = nextSmallerElement(arr, n);

    for(int i=0;i<n;i++){
        int length = nextS[i] - prevS[i] - 1;
        result[length - 1] = max(result[length - 1], arr[i]);
    }

    for(int i=n-2;i>=0;i--){
        result[i] = max(result[i+1], result[i]);
    }

    return result;
}

int main(){
    int numArr[] = {10,20,30,50,10,70,30};
    vector<int> result = maxOfMin(numArr, 7);
    for(auto value : result) cout << value << " ";
    cout << endl;

    return 0;
}