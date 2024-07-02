#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

int arithmetic(int a, int b, char c){
    if(c == '+') return a + b;
    else if (c == '-') return b - a;
    else if (c == '*') return a * b;
    else if (c == '/') return b / a;
    else return -1;
}

long long postFixEvaluation(string str) {
    stack<int> numbers;
    long long result = 0;
    unordered_set<char> operators {'^', '+', '-', '*', '/'};
    for(int i=0;i<str.length();i++) {
        char c = str[i];
        if(!operators.count(c)) numbers.push(c - '0');
        else {
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            result = arithmetic(a, b, c);
            numbers.push(result);
        }
    }

    return result;
}

long long preFixEvaluation(string str){
    stack<int> numbers;
    long long result = 0;
    unordered_set<char> operators {'^', '+', '-', '*', '/'};

    for(int i=str.length()-1;i>=0;i--){
        char c = str[i];
        if(!operators.count(c)) numbers.push(c - '0');
        else {
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            result = arithmetic(b,a,c);
            numbers.push(result);
        }
    }

    return result;
}

int main(){
    string str = "+*123";
    long long result = preFixEvaluation(str);
    cout << result << endl;
    return 0;
}