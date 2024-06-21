#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Time Complexity = O(n*logn) and Space Complexity = O(n)
void countFreq1(string str) {
    map<char, int> freqMap;
    for(int i=0; i<str.length();i++) freqMap[str[i]]++;

    for(auto pair : freqMap) cout << pair.first << " " << pair.second << endl;
}

// Time Complexity = O(n) and Space Complexity = O(1)
void countFreq2(string str){
    vector<int> count(26,0);
    for(int i=0;i<str.length();i++) count[str[i] - 'a']++;

    for(int i=0;i<26;i++) if(count[i]>0) cout << char('a' + i) << " " << count[i] << endl;
}

int main(){
    char str[] = "geeksforgeeks";
    printf("%s\n",str);
    countFreq2(str);
    return 0;
}