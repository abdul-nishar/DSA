#include <iostream>

using namespace std;

// Better Solution
bool isPalindrome(string str){
    bool result = true;
    for(int i=0;i<str.length()/2;i++) if(str[i] != str[str.length() - 1 - i]) {result=false;break;}

    return result;
}

// bool isPalindrome(string str){
//     string rev = str;
//     reverse(rev.begin(),rev.end());

//     return rev == str;
// }

int main(){
    string testStr = "ABCBA";
    cout << isPalindrome(testStr);
    return 0;
}
