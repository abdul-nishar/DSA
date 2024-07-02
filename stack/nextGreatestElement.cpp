#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreatestElement(int arr[], int n) {
    vector<int> result(n);
    stack<int> numbers;
    int mover = n-1;
    while(mover >= 0){
        if(numbers.empty() || numbers.top() > arr[mover]) {
            int value = numbers.empty() ? -1 : numbers.top();
            result[mover] = value;
            numbers.push(arr[mover]);
            mover--;
         }
        else numbers.pop();
    }

    return result;
}

int main(){
    int numArr[] = {50};
    vector<int> result = nextGreatestElement(numArr, sizeof(numArr)/sizeof(numArr[0]));
    for(auto value : result) cout << value << " ";
    return 0;
}