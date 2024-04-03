#include <iostream>
#include <vector>
#include <string>

using namespace std;

// void swap(int a, int b){
//     a ^= b;
//     b ^= a; 
//     a ^= b;
//     cout<< a << " " << b;
//  }

// int log2(int x) { 
//     int res = 0; 
//     while (x >>= 1) 
//         res++; 
//     return res; 
// }

// bool isSet(int n, int k){
//     if((n & (1<<(k-1)))==0) return false;
//     else return true;
// }

// int pos(int n){
//     int result=0;
//     int temp=n;
//     while(temp>>=1) result++;
//     for(int i =1;i<=result+1;i++){
//         if(((1<<(i-1))&n)!=0) return i;
//     }
//     return 0;
// }

// int countSetBits(int number,int *values){
//     // int output=0;

//     ///////////////////////// Method-1 ///////////////////////////////////////

//     // int temp=number;
//     // for(int i=0;i<(log(number)/log(2));i++){
//     //     if((temp&1)!=0) output++;
//     //     temp>>=1;
//     // }
//     // return output;

//     ///////////////////////// Method-2(Brian-Kerningam Method) ///////////////////////////////////////
//     // while(number>0){
//     //     number=number&(number-1);
//     //     output++;
//     // }
//     // return output;

//     ///////////////////////// Method-3 //////////////////////////////////
//     return values[(number>>24)&255] + values[(number>>16)&255] + values[(number>>8)&255] + values[number&255];
// }

////////////////////////////////////////////////////////////////
//This function returns all the set bits in numbers from 1 to n:
// int countAllSetBits(int n){

// 		int powerOfTwo=1;
//         int output=0;
//         for(int i=0;i<=(log(n)/log(2));i++){
//             int x = (n+1)/powerOfTwo;
//             if(x%2!=0){
//                 output+=(x/2)*powerOfTwo + (n+1)%powerOfTwo;
//             }else{
//                 output+=(x/2)*powerOfTwo;
//             }
//             powerOfTwo*=2;
//         }
//        return output;
// }

//////////////////////////////////////////////////////////////////

// bool isPowerOfTwo(long long number){
//     ////////////////////////////// Method - 1 //////////////////////////////////
//     // int count=0;
//     // while(number>0){
//     //     number=number&(number-1);
//     //     count++;
//     // }
//     // if(count==1) return true;
//     // else return false;

//     /////////////////////////////// Method - 2 /////////////////////////////////////////////
//     if(number==0) return false;
//     return (number&(number-1))==0;
// }

////////////////////////////////////////////////////////////////

// int onlyOddOccuringNumber(int arr[], int n){
//     int output=arr[0];
//     for(int i=1;i<n;i++){
//         output= output^arr[i];
//     }
//     return output;
// }

////////////////////////////////////////////////////////////////

// int arr[]= {2,2,4,5,5,6,6,6,8,8};
// void twoOddOccuring(int arr[], int n){
//     int output=arr[0];
//     int res1=0;
//     int res2=0;

//     for(int i=1;i<n;i++){
//         output= output^arr[i];
//     }
//     int k=output&(~(output-1));
//     for(int i=0;i<n;i++){
//         if((k&arr[i])!=0){
//           res1= res1^arr[i];
//         }
//         else{
//             res2=res2^arr[i];
//         }
//     }
//     cout<<res1<<" "<<res2;
//     return;
// }

////////////////////////////////////////////////////////////////

// void powerSet(string s){
//     int stringLength = s.length();
//     int powerSetLength = pow(2,stringLength);

//     for(int i=0;i<powerSetLength;i++){
//         for(int j=0;j<stringLength;j++){
//             if(((i)&(1<<j))!=0) cout<<s[j];
//         }
//         cout<<endl;
//     }
//     return;
// }

////////////////////////////////////////////////////////////////

// unsigned int swapBits(unsigned int n){
//     int evenBits = n & 0xAAAAAAAA;
//     int oddBits = n & 0x55555555;
    	
//     evenBits>>=1;
//     oddBits<<=1;
    	
//     return (evenBits | oddBits) ;
// }

////////////////////////////////////////////////////////////////

// int maxANDValue(int arr[], int N){
//     int maxValue = 0;
//     for(int i=0;i<N;i++){
//         if(arr[i]>maxValue) maxValue = arr[i];
//     }

//     int result=0;
//     for(int bit=log2(maxValue); bit>=0;bit--){
//         int count=0;
//         int pattern = result | 1 << bit;
//         for(int i=0;i<N;i++){
//             if((pattern&arr[i]) == pattern) count++;
//         }
//         if(count>=2) result |= pattern;
//     }
//     return result;
// }

////////////////////////////////////////////////////////////////////////

// int binaryToGrayCode(int n){
//     int grayCode = n ^ (n>>1);
//     return grayCode; 
// }

////////////////////////////////////////////////////////////////////////

int grayToBinaryCode(int n){
    int logValue = log2(n);
    int binaryCode = 1 << logValue;
    for(int i=0;i<=logValue;i++) {
        binaryCode = (binaryCode >> 1) ^ n;
    }
    return binaryCode;
}
int main(){
    int input;
    cin>>input;
    cout<< grayToBinaryCode(input);
}