#include <iostream>
#include <stack>

using namespace std;

vector<int> prevSmallerElement(int arr[], int n) {
    stack<int> numbers;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        while (!numbers.empty() && arr[numbers.top()] >= arr[i]) {
            numbers.pop();
        }
        result[i] = numbers.empty() ? -1 : numbers.top();
        numbers.push(i);
    }
    return result;
}

vector<int> nextSmallerElement(int arr[], int n) {
    vector<int> result(n);
    stack<int> numbers;
    for (int i = n - 1; i >= 0; i--) {
        while (!numbers.empty() && arr[numbers.top()] >= arr[i]) {
            numbers.pop();
        }
        result[i] = numbers.empty() ? n : numbers.top();
        numbers.push(i);
    }
    return result;
}

vector <int> maxOfMin(int arr[], int n)
{
    vector<int>result(n,INT_MIN);
    
    vector<int> prevSmaller = prevSmallerElement(arr, n);
    vector<int> nextSmaller = nextSmallerElement(arr, n);
    
    for(int i=0;i<n;i++){
        int length = nextSmaller[i] - prevSmaller[i] - 1;
        result[length-1] = max(arr[i],result[length-1]);
    }
    
    for (int i = n - 2; i >= 0; i--){
        result[i] = max(result[i], result[i + 1]);
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