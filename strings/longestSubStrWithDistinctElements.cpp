#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubStrWithDistinctElements(string str) {
    unordered_map<char,int> indexMap;

    int result = 0;

    int left = 0, right = 0;

   while(right < str.length() && left <= right) {
        if(indexMap.count(str[right])){
            if(left <= indexMap[str[right]]) left = indexMap[str[right]] + 1; 
        }

        indexMap[str[right]] = right;
        result = max(result, right - left + 1);

        right++;
   }

    return result;
}

int main(){
    string str = "abaacdbab";
    cout << longestSubStrWithDistinctElements(str);
    return 0;
}

