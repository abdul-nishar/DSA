#include <iostream>
#include <cmath>

using namespace std;
#define d 256 

int hashValue(string str, int q){
    int sum = 0;
    for(int i=0; i<str.length(); i++) sum = (sum * d + (str[i] - '0')) % q;
    return sum;
}

bool search(string pat, string txt, int q) 
{ 
    int m = pat.length();
    int n = txt.length();
    int pattHashVal = hashValue(pat, q);
    int currHashVal = hashValue(txt.substr(0, m), q);
    
    int h = 1;
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (pattHashVal == currHashVal) {
            if (txt.substr(i, m) == pat) return true;
        }
        if (i < n - m) {
            currHashVal = (d * (currHashVal - (txt[i] - '0') * h) + (txt[i + m] - '0')) % q;
            if (currHashVal < 0) {
                currHashVal = (currHashVal + q);
            }
        }
    }
    
    return false;
} 

int main(){
    string pattern = "abc";
    string txt = "abdabcbabc";
    search(pattern, txt, 79);

    return 0;
}