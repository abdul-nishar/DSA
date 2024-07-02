#include <iostream>
#include <stack>
#include <vector>

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

void maxRectArea(int arr[], int n) {
    vector<int> prevS = prevSmallerElement(arr, n);
    vector<int> nextS = nextSmallerElement(arr, n);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {

        int height = arr[i];
        int width = nextS[i] - prevS[i] - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }

    cout << "Maximum Rectangular Area: " << maxArea << endl;
}

// More Efficient Method
void maxRectArea2(int arr[], int n){
    stack<int> prevIdxStack;
    int maxArea = 0;

    for(int i=0; i<=n;i++){
        while(!prevIdxStack.empty() && (i==n || arr[prevIdxStack.top()] >= arr[i])){
            int height = arr[prevIdxStack.top()];
            prevIdxStack.pop();
            int width = prevIdxStack.empty() ? i : i - prevIdxStack.top() - 1;
            maxArea = max(maxArea, height*width);
        }
        prevIdxStack.push(i);
    }

    cout << " Maximum rectangle area : " << maxArea << endl;
}

int main(){
    int numArr[] = {7,2,8,9,1,3,6,5};
    maxRectArea2(numArr, sizeof(numArr)/sizeof(numArr[0]));
    return 0;
}