#include <iostream>
#include <vector>
using namespace std;

void bucketSort(int arr[], int n, int k) {
    int maxValue = INT_MIN;
    for(int i = 0; i < n; i++) maxValue = max(arr[i], maxValue);

    maxValue = maxValue + 1; // Required so that valid index is from 0 to k-1

    vector<int> bucket[k];

    // Placing the elements into their corresponding buckets
    for(int i = 0; i < n; i++){
        int bucketIdx = (k * arr[i])/maxValue; // expression to get the index of the bucket for the current element
        bucket[bucketIdx].push_back(arr[i]);
    }

    // Sorting the individual buckets
    for(int i = 0; i < k; i++) sort(bucket[i].begin(), bucket[i].end());

    // Combining the elements together
    int index = 0;
    for(int i = 0; i < k; i++) {
        for(int j=0;j<bucket[i].size();j++) arr[index++] = bucket[i][j];
    }
}

int main(){
    int numbersArray[] = {20,88,70,85,75,95,18,82,60};
    bucketSort(numbersArray, sizeof(numbersArray)/sizeof(numbersArray[0]), 5);
    for(int i=0; i<sizeof(numbersArray)/sizeof(numbersArray[0]);i++) cout << numbersArray[i] << " ";
    return 0;
}