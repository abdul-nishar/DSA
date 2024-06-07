#include <iostream>
#include <vector>
using namespace std;

 void twoArraySort(vector<int>& arr1, int& p1,vector<int>& arr2,int& p2, int& p3, vector<int>& mergedVector){
        while(p1<arr1.size() && p2<arr2.size()){
               if(arr1[p1]<=arr2[p2]){
                    mergedVector[p1+p2+p3] = arr1[p1]; 
                    p1++;
                }else{
                    mergedVector[p1+p2+p3] = arr2[p2];
                    p2++;
                } 
        }
    }
    
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        vector <int> mergedVector(A.size()+B.size()+C.size());
        int p1=0,p2=0,p3=0;
        while(p1<A.size() && p2<B.size() && p3<C.size()){
            if(A[p1]<=B[p2] && A[p1]<=C[p3]){
                mergedVector[p1+p2+p3] = A[p1];
                p1++;
            }else if(B[p2]<=C[p3] && B[p2]<=A[p1]){
                mergedVector[p1+p2+p3] = B[p2];
                p2++;
            }else if(C[p3]<=A[p1] && C[p3]<=B[p2]){
                mergedVector[p1+p2+p3] = C[p3];
                p3++;
            }
        }


        if(p1==A.size()) twoArraySort(B, p2, C, p3,p1, mergedVector);
        else if(p2==B.size()) twoArraySort(A, p1, C, p3,p2, mergedVector);
        else if(p3==C.size()) twoArraySort(A, p1, B, p2,p3, mergedVector);
        
        if(p1==A.size() && p2==B.size()) {
            while(p3<C.size()){
                mergedVector[p1+p2+p3] = C[p3];
                p3++;
            }
        }
        
        else if(p2==B.size() && p3==C.size()) {
            while(p1<A.size()){
                mergedVector[p1+p2+p3] = A[p1];
                p1++;
            }
        }
        else if(p1==A.size() && p3==C.size()) {
            while(p2<B.size()){
                mergedVector[p1+p2+p3] = B[p2];
                p2++;
            }
        }
        
        return mergedVector;
    } 

int main(){
    vector<int> numbersArray1 = {1,2,3,4};
    vector<int> numbersArray2 = {1,2,3,4,5};
    vector<int> numbersArray3 = {1,2,3,4,5,6};

    vector <int> result = mergeThree(numbersArray1, numbersArray2, numbersArray3);
    for(auto value : result) cout << value << " "; 
    return 0;
}