#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    
    queue<pair<string,int>> q;
    
    q.push({startWord,1});
    
    while(!q.empty()){
        string word = q.front().first;
        int count = q.front().second;
        q.pop();
        
        for(int i=0;i<word.length();i++){
            string original = word;
            for(char c = 'a'; c <= 'z'; c++){
                original[i] = c;
                if(wordSet.count(original)) {
                    if(original == targetWord) return count + 1;
                    q.push({original,count+1});
                    wordSet.erase(original);
                }
            }
        }
    }
    
    return 0;
}