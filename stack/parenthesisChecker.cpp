#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool parenthesisChecker(string str) {
    unordered_map<char, char> bracketMap{{'(', ')'}, {'{', '}'}, {'[', ']'}};
    stack<char> bracketStack;

    for (char c : str) {
        // Checking if the current char is an opening bracket
        if (bracketMap.count(c)) {
            // Pushing it in the stack if it is
            bracketStack.push(c);
        } else {
            // Condition check for closing bracket

            // Checking if the stack is empty which means closing bracket occurs before opening bracket
            // Or if the current char is the same the closing bracket of the bracket at the top of the stack
            if (bracketStack.empty() || bracketMap[bracketStack.top()] != c) {
                return false;
            }
            // Poping off the top of the stack
            bracketStack.pop();
        }
    }

    // Returning whether the stack is empty or not
    return bracketStack.empty();
}

int main(){
    stack<int> stack;
    string str = "[()]{}{[()()]()}";
    cout << boolalpha << parenthesisChecker(str);
    return 0;
}