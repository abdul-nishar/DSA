#include <iostream>
#include <vector>
using namespace std;


vector<int> findUnion(int arr1[], int n,int arr2[], int m){
   int p1 = 0, p2 = 0;
    vector<int> result;

    while (p1 < n && p2 < m) {
        if (arr1[p1] == arr2[p2]) {
            if (result.empty() || result.back() != arr1[p1]) {
                result.push_back(arr1[p1]);
            }
            p1++;
            p2++;
        } else if (arr1[p1] < arr2[p2]) {
            if (result.empty() || result.back() != arr1[p1]) {
                result.push_back(arr1[p1]);
            }
            p1++;
        } else {
            if (result.empty() || result.back() != arr2[p2]) {
                result.push_back(arr2[p2]);
            }
            p2++;
        }
    }

    while (p1 < n) {
        if (result.empty() || result.back() != arr1[p1]) {
            result.push_back(arr1[p1]);
        }
        p1++;
    }

    while (p2 < m) {
        if (result.empty() || result.back() != arr2[p2]) {
            result.push_back(arr2[p2]);
        }
        p2++;
    }

    return result;
}

int main(){
    int numbersArray1[] = {-6,-6,-5,-4,-3,0};
    int numbersArray2[] = {-5,2,2};
    vector <int> result = findUnion(numbersArray1, sizeof(numbersArray1)/sizeof(numbersArray1[0]), numbersArray2, sizeof(numbersArray2)/sizeof(numbersArray2[0]));

    for(auto value : result) cout << value << " ";
    return 0;
}