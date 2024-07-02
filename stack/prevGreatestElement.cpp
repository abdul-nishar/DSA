#include <iostream>
#include <stack>

using namespace std;

void prevGreatestElement(int arr[], int n) {
    stack<int> numbers;
    int mover = 0;
    while(mover < n){
        if(numbers.empty() || numbers.top() > arr[mover]) {
            int value = numbers.empty() ? -1 : numbers.top();
            cout << value << " ";
            numbers.push(arr[mover]);
            mover++;
         }
        else numbers.pop();
    }
}

int main(){
    int numArr[] = {20,30,10,5,15};
    prevGreatestElement(numArr, sizeof(numArr)/sizeof(numArr[0]));
    return 0;
}