#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1= nums1.size(), n2 = nums2.size();

    if(n1 > n2) return findMedianSortedArrays(nums2,nums1);

    if(n1 == 0){
        if(n2%2 == 0) return (double)(nums2[n2/2]+nums2[n2/2 - 1])/2;
        else return nums2[n2/2];
    }else if(n2==0){
        if(n1%2 == 0) return (double)(nums1[n1/2]+nums1[n1/2 - 1])/2;
        else return nums1[n1/2];
    }

    int low = 0, high = n1;
    int min1,min2,max1,max2;

    while(low<=high){
        int p1 = (low+high)/2;
        int p2 = (n1+n2+1)/2 - p1;
        min1 = (p1>=n1) ? INT_MAX : nums1[p1];
        min2 = (p2>=n2) ? INT_MAX : nums2[p2];
        max1 = (p1<=0) ? INT_MIN: nums1[p1-1];
        max2 = (p2<=0) ? INT_MIN: nums2[p2-1];
        if(min1>=max2 && max1<=min2) break;
        else if(min1<max2){
            low=p1+1;
        } else{
            high=p1-1;
        }
    }

    int firstValue = max(max1, max2);
    int secondValue = min(min1, min2);
    double result;

    if((n1+n2 & 1) != 1) result = (double)(firstValue+secondValue)/2;
    else result = firstValue;
    
    return result;
}

int main(){
    vector<int> numbersArray1 = {2};
    vector<int> numbersArray2 = {1,2,3,5,6};
    cout << findMedianSortedArrays(numbersArray1, numbersArray2);
    return 0;
}

