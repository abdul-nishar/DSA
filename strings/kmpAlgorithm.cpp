#include <iostream>
#include <vector>
using namespace std;

bool kmpAlgorithm(string txt, string patt) {
    vector<int> lmpArr(1,0);
    int curLen = 0;
    for(int i=1;i<patt.length();i++){
        if(patt[curLen] == patt[i]) {curLen++;lmpArr.push_back(curLen);}
        else {
            if(curLen == 0) lmpArr.push_back(0);
            else {curLen = lmpArr[curLen-1];i--;}
        }
    }
    int i=0, j =0;
    while(i<txt.length()) {
        if(txt[i] == patt[j]) {
            i++; j++;
            if(j == patt.length()) return true;
        }
        else {
            if(j == 0) i++;
            else j = lmpArr[j - 1];
        }
    }

    return false;
}

int main(){
    string text = "abaaccbdabceabad";
    string pattern = "abad";
    cout << kmpAlgorithm(text,pattern);
    return 0;
}
