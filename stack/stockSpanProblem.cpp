#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Uses more auxiliary space than required
vector <int> stockSpanProblem(int price[], int n){
    // Declaration 
    vector<int> spanVec;
    stack<int> priceStack;
    vector<int> next(n);
   // Initialization
   spanVec.push_back(1);
   priceStack.push(price[0]);
   
   int count = 1, mover = 1, pointer = 0;
   
   while(mover < n){
       if(priceStack.empty() || priceStack.top() > price[mover]){
           spanVec.push_back(count);
           pointer = mover;
           count = 1;
           priceStack.push(price[mover]);
           mover++;
       }else{
           priceStack.pop();
           count += spanVec[pointer];
           pointer -= spanVec[pointer];
       }
   }
   
   return spanVec;
}

// More Efficient Solution
vector<int> stockSpanProblem2(int price[], int n){
    vector<int> spanVec(n);
    stack<int> indexStack;

    spanVec[0] = 1;  // The span of the first day is always 1
    indexStack.push(0);

    for (int i = 1; i < n; i++) {
        // Pop elements from the stack while the stack is not empty and the current price is higher than the price at the top index of the stack
        while (!indexStack.empty() && price[i] >= price[indexStack.top()]) {
            indexStack.pop();
        }

        // If the stack is empty, it means the current price is greater than all previous prices
        spanVec[i] = indexStack.empty() ? (i + 1) : (i - indexStack.top());

        // Push the current index onto the stack
        indexStack.push(i);
    }

    return spanVec;
}

int main(){
    int numsArr[] = {13,15,12,14,16,8,6,4,10,30};
    vector <int> result = stockSpanProblem2(numsArr, sizeof(numsArr)/sizeof(numsArr[0]));
    for (auto value: result) cout << value << " ";
    return 0;
}