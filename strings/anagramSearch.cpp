#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int hashValue(string str, int q){
    int sum = 0;
    for(int i=0;i<str.length();i++) sum += (str[i]-'0') % q;
    return sum;
}

bool anagramSearch(string txt, string pat, int q) {
    int m = pat.length();
    int n = txt.length();
    
    int patHashValue = hashValue(pat, q);
    int curHashValue = hashValue(txt.substr(0,m), q);

    for(int i=0;i<=n-m;i++){
        if(patHashValue == curHashValue) return true;
        if(i < n-m){
            curHashValue = (curHashValue - (txt[i]-'0') + (txt[i+m]-'0'))%q;
            if(curHashValue < 0) curHashValue = curHashValue + q;
        }
    }

    return false;
}

int main(){
    string str = "geeksforgeeks";
    string pat = "frog";
    cout << anagramSearch(str, pat, 97);
    return 0;
}