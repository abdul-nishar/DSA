#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> result;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    if (!wordSet.count(endWord)) {
        return result;
    }

    queue<vector<string>> q;
    q.push({beginWord});

    bool found = false;
    unordered_set<string> visitedThisLevel;

    while (!q.empty()) {
        int len = q.size();
        visitedThisLevel.clear();

        for (int i = 0; i < len; ++i) {
            vector<string> library = q.front();
            q.pop();
            string word = library.back();

            for (int j = 0; j < word.length(); ++j) {
                string original = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    original[j] = c;

                    if (wordSet.count(original)) {
                        vector<string> newPath = library;
                        newPath.push_back(original);

                        if (original == endWord) {
                            result.push_back(newPath);
                            found = true;
                        } else {
                            q.push(newPath);
                            visitedThisLevel.insert(original);
                        }
                    }
                }
            }
        }

        for (auto word : visitedThisLevel) wordSet.erase(word);

        if (found) break;
    }

    return result;
}