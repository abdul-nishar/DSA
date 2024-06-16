#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long getCount(int n) {
    if (n == 1) return 10;
    unordered_map<int, vector<int>> optionsMap{
        {0, {8, 0}},
        {8, {0, 7, 9, 5, 8}},
        {7, {8, 4, 7}},
        {9, {8, 6, 9}},
        {5, {8, 4, 6, 2, 5}},
        {4, {7, 5, 1, 4}},
        {6, {5, 9, 3, 6}},
        {2, {5, 1, 3, 2}},
        {1, {4, 2, 1}},
        {3, {2, 6, 3}}
    };

    vector<vector<long long>> dp(n, vector<long long>(10, 0));
    
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }

    // For each move move from 1 to n-1, and each digit digit, we update the next possible digit's counts using the optionsMap

    for (int move = 1; move < n; ++move) {
        for (int digit = 0; digit < 10; ++digit) {
            for (int nextDigit : optionsMap[digit]) {
                dp[move][nextDigit] += dp[move - 1][digit];
            }
        }
    }

    long long count = 0;
    for (int digit = 0; digit < 10; ++digit) {
        count += dp[n - 1][digit];
    }

    return count;
}

int main(){
    cout << getCount(9);
    return 0;
}