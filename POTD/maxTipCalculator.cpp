#include <iostream>
#include <vector>
using namespace std;

void sortByValues(vector<int>& arr1, const vector<int>& arr2) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < arr1.size(); ++i) {
        pairs.push_back({arr1[i], arr2[i]});
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < arr1.size(); ++i) {
        arr1[i] = pairs[i].first;
    }
}

long long maxTipCalculator(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
    long long total = 0;
    vector<int> diff;
    for(int i = 0; i<n; i++) diff.push_back(abs(arr[i] - brr[i]));
    sortByValues(arr, diff);
    sortByValues(brr, diff);

    int countX = x, countY = y, p1 = n-1;
    while(countX > 0 && countY > 0 && p1 >= 0){
        int curVal;
        if(arr[p1] >= brr[p1] && countX > 0) {curVal = arr[p1];countX--;}
        else if(countY > 0) {curVal = brr[p1];countY--;}

        p1--;
        total+=curVal;
    }

    if(p1 >= 0){
        while(countX > 0 ) {total += arr[p1--];countX--;}
        while(countY > 0) {total += brr[p1--];countY--;}
    }

    cout << "--------------------------------arr----------------------------" << endl;
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "--------------------------------brr----------------------------" << endl;
    for(int i = 0; i<n; i++) cout << brr[i] << " ";
    cout << endl;

    cout << "--------------------------------diff----------------------------" << endl;
    for(int i = 0; i<n; i++) cout << diff[i] << " ";
    cout << endl;
 
    return total;
}

int main(){
    vector<int> arr1 = {4,7,10,8,7,3,2,8,7};
    vector<int> arr2 = {3,9,5,5,5,6,8,6,7};
    cout << maxTipCalculator(9, 4, 7, arr1, arr2);
    return 0;
}
