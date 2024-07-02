#include <iostream>
#include <stack>

using namespace std;

int precedenceFunc(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void infixToPostfix(string str) {
    stack<char> operatorStack;
    string result = "";

    for(int i = 0; i < str.length(); i++) {
        char c = str[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        
        else if(c == '(') operatorStack.push(c);
        
        else if(c == ')') {
            while(operatorStack.top() != '(') {
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        
        else {
            while(!operatorStack.empty() && precedenceFunc(operatorStack.top()) >= precedenceFunc(c)) {
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while(!operatorStack.empty()) {
        result += operatorStack.top();
        operatorStack.pop();
    }

    cout << result << endl;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);

    return 0;
}