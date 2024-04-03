#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

//----------------------------- Problem - 2 -----------------------------------//

// int prefixSum(int arr[], int index){
//     int sum = 0;
//     for(int i=0; i<index; i++){
//         sum+=arr[i];
//     }
//     return sum;
// }

// int equivalentIndex(int arr[],int n){
//     int totalSum = prefixSum(arr,n);
//     for(int i=1; i<n; i++){
//         if(prefixSum(arr,i)==(totalSum - prefixSum(arr,i+1)))return i;
//     } return -1;
// }

// ------------------------------ Problem - 3 ---------------------------------------------//

// void mergeArrays(int arr1[],int arr2[],int m,int n){
//     int arr3[m+n];
//     int i=0,j=0,k=0;
//     while(i<m && j<n){
//         if(arr1[i]<arr2[j]) arr3[k++]=arr1[i++];
//         else if(arr1[i]>arr2[j]) arr3[k++]=arr2[j++];
//         else {
//             arr3[k++]=arr1[i++];
//             arr3[k++]=arr2[j++];
//         }
//     }
//     while(i<m) arr3[k++] = arr1[i++];
//     while(j<m) arr3[k++] = arr2[j++];

//     for(int i=0; i<m+n; i++){
//         cout<<arr3[i]<<" ";
//     }
// }

// ---------------------------------------------------------------- //
// int largestElement(int arr[],int n){
//     int largest=arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]>largest) largest=arr[i];
//     }
//     return largest;
// }

// ---------------------------- Incomplete solution ------------------------------------ // 
// int indexDiff(int arr[], int n, int start){
//         int index=start;
//         for(int i=start;i<n;i++){
//             if(arr[i]>=arr[start]) index=i;
//         }
//         return index - start;
//     }
    
//     int maxIndexDiff(int A[], int N) 
//     { 
//         int indexDiffMax=0;
//         for(int i=0;i<N;i++){
//             int diff = indexDiff(A,N,i);
//             if(diff>indexDiffMax) indexDiffMax = diff;
//         }
//         return indexDiffMax;
//     }

// ---------------------------------------------------------------- //

// int secondLargest(int arr[], int n){
//     int largest = arr[0];
//     for(int i=0; i<n; i++){
//         if(arr[i]>largest) largest = arr[i];
//     }
//     int secLargest=-1;
//     for(int i=0; i<n; i++){
//         if(arr[i]>secLargest && arr[i]<largest) secLargest = arr[i];
//     }
//     return secLargest;
// }
// *************************Efficient Method************************ //

// int secondLargest(int arr[],int n){
//     int largest = arr[0], result = -1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             result = largest;
//             largest = arr[i];
//         }else if(arr[i]< largest && arr[i]>result){
//             result = arr[i];
//         }
//     }
//     return result;
// }
//----------------------------------------------------------------//

// bool isSorted(int arr[], int n){
//     bool sorted = true;
//     for(int i=1; i<n; i++){
//         if(arr[i]<arr[i-1]) {
//             sorted = false;
//             break;
//         }
//     }
//     return sorted;
// }

// ---------------------------------------------------------------- // 

//  bool checkRotatedAndSorted(int arr[], int num){
        
//         // Your code here
//         int max=arr[0];
//         for(int i=1;i<num;i++){
//             if(arr[i]>max) max=arr[i];
//         }
//         int min=arr[0];
//         for(int i=1;i<num;i++){
//             if(arr[i]<min) min=arr[i];
//         }
//         bool sortedAndRotated1 = false;
//         for(int i=0;i<num;i++){
//             if(i!=num-1 ? arr[i]>arr[i+1] : arr[i]>arr[0]){
//                 if(arr[i] == max && i!=(num-1)) sortedAndRotated1 = true;
//                 else {
//                     sortedAndRotated1 = false;
//                     break;
//                 };
//             }
//         }
//         bool sortedAndRotated2 = false;

//         for(int i=0;i<num;i++){
//             if(i!=num-1 ? arr[i]<arr[i+1] : arr[i]<arr[0]){
//                 if(arr[i] == min && i!=num-1) sortedAndRotated2 = true;
//                 else {
//                     sortedAndRotated2 = false;
//                     break;
//                 };
//             }

//         }
//         return sortedAndRotated1 || sortedAndRotated2;
//     }

// ---------------------------------------------------------------- //
// void reverseArray(int arr[],int n){
//     int size = n%2!=0 ? n/2 + 1 : n/2;
//     for(int i=0;i<size;i++){
//         int tempStore = arr[i];
//         arr[i] = arr[n-1-i];
//         arr[n-1-i] = tempStore;
//     }
// }

// ---------------------------------------------------------------- //
// int removeDuplicates(int arr[], int n){
//     int res = 1;
//     for(int i=1; i<n; i++){
//         if(arr[i] != arr[res - 1]){
//             arr[res] = arr[i];
//             res++;
//         }
//     }
//     return res;
// }

// ---------------------------------------------------------------- //
 
// void moveZeroesToEnd (int arr[], int n){
//     int temp = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i] != 0){
//             arr[temp++] = arr[i];
//         }
//     }
//     for(int i=temp; i<n; i++){
//         arr[i] = 0;
//     }
// }

// ---------------------------------------------------------------- // 
// void leftRotateByK(long long arr[], int n, int k){
//     int max = arr[0];
//     for(int i=1; i<n; i++){
//         if(arr[i] > max) max = arr[i];
//     }
//     for(int i=0; i<n; i++){
//         int temp = (i+k>=n) ? (i+k)%n : i+k;
//         arr[i] += (arr[temp]%(max+1)*(max+1)); 
//     }

//     for(int i=0; i<n; i++){
//         arr[i] /= max+1;
//     }
// }   

// ---------------------------------------------------------------- //

// void printLeaders(long long arr[], int n){
//     int currentLeader = arr[n-1];
//     cout<<currentLeader<< " ";
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]>currentLeader){
//             cout<<arr[i]<<" ";
//             currentLeader=arr[i];
//         }
//     }
// }

// ---------------------------------------------------------------- //

// int maxDiff(long long arr[], int n){
//     int res = arr[1] - arr[0];
//     int minVal = arr[0];

//     for(int i = 1; i < n; i++){
//         res = fmax(res,arr[i] - arr[minVal]);
//         minVal = fmin(minVal,arr[i]);
//     }
//     return res;
// }

// ---------------------------------------------------------------- //
// void rearrange(long long *arr, int n){
//     for(int i=0;i<n;i=i+2){
//         int temp=arr[n-1];
//         for(int j=n-1;j>i;j--){
//             arr[j] = arr[j-1];
//         }
//         arr[i] = temp;
//     }
// }

// ---------------------------------------------------------------- //

// void printFrequencySorted(long long arr[], int n){
//     long long temp = arr[0];
//     int count = 1;
//     for(int i=1;i<n;i++){
//         if(arr[i] == temp){
//             count++;
//         }else{
//             cout<<temp<<" : "<<count<<endl;
//             temp=arr[i];
//             count=1;
//         }
//         if(i==n-1)cout<<temp<<" : "<<count<<endl;
//     }
// }

// ---------------------------------------------------------------- //

// void frequencyCount(vector<int>& arr,int N, int P){ 
//         vector <int> frequency(N);

//         for(int i=0;i<N;i++){
//             if(arr[i]<=N) frequency[arr[i]-1] += 1;
//         }
//         for(int i=0;i<N;i++){
//             arr[i] = frequency[i];
//         }
//     }


// ---------------------------------------------------------------- //

// int maxProfit(int arr[], int n){
//     int profit = 0;
//     for(int i=0;i<n-1;i++){
//         if(arr[i+1]>arr[i]){
//         profit += arr[i+1] - arr[i];
//         }
//     }

//     return profit;
// }

// ---------------------------------------------------------------- //

//  long long trappingWater(int arr[], int n){
//         // code here
//         int leftWall[n],rightWall[n];
        
//         int leftMax = arr[0];
//         for(int i=0;i<n;i++){
//             leftMax = fmax(leftMax,arr[i]);
//             leftWall[i] = leftMax;
//         }
        
//         int rightMax = arr[n-1];
//         for(int i=n-1;i>=0;i--){
//             rightMax = fmax(rightMax,arr[i]);
//             rightWall[i] = rightMax;
//         }
        
//         long long waterAmount = 0;
//         for(int i=0;i<n;i++){
//             waterAmount += fmin(leftWall[i],rightWall[i]) - arr[i];
//         }
        
//         return waterAmount;
//     }

// ----------------------- Maybe Error in Input Cases in GFG ----------------------------------------- //

// long long numGame(long long n) {
//         // code here
//         long long result = 1;
        
//         for(long long i=2;i<=n;i++){
//             long long temp=i;
//             for(long long j=2;j<ceil((log2(i) + 1));j++){
//                 if(i%j==0 && i!=j) temp=1;
//             }
            
//             if(temp!=1){
//                 while(temp*i<=n){
//                     temp *= i;
//                 }
            
//                 result = result*temp;
//             }
//         }
        
//         return result;
//     }

// ---------------------------------------------------------------- //

// int maxConsecutive1(int arr[], int n) {
//     int result = 0;
//     int noOfOnes = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==1) noOfOnes++;
//         else {
//             if(noOfOnes>result) result=noOfOnes;
//             noOfOnes=0;
//         }
//         if(i==n-1 && noOfOnes>result) result=noOfOnes; 
//     }
//     return result;
// }

// ---------------------------------------------------------------- //

int maxSumSubArray(int arr[], int n) {
    
}

int main(){
    // int arr[];
    int arr[] = {2,3,-8,7,-1,2,3};
    cout<<maxSumSubArray(arr,7);
    // cout<<trappingWater(arr,5);
    // for(int i=0; i<5; i++){
    //     cout<< arr[i]<<" ";
    // }
}