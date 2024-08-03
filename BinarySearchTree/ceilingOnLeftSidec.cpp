#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> ceilingOnLeftSide(int arr[], int n) {
    vector<int> result;
    set<int> numSet;

    for(int i = 0; i < n; i++){
        auto iterator = numSet.begin();
        for(; iterator != numSet.end(); iterator++){
            if(*iterator >= arr[i]) {
                result.push_back(*iterator);
                break;
            }
        }

        if(iterator == numSet.end()) result.push_back(-1);

        numSet.insert(arr[i]);
    }

    return result;
}

int main(){
    int numArr[] = {2,8,30,15,25,12};

    vector<int> result = ceilingOnLeftSide(numArr, sizeof(numArr)/ sizeof(numArr[0]));

    for(auto value : result) cout << value << " ";

    return 0;
}