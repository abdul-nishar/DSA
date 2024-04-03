#include <iostream>
#include <vector>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////

// ----------------------------- METHOD - 1 ----------------------------------- //

// int num = 1000000007;
// long long power(long long N,int R)
//     {   
//         if(R==1) return N;
//         if(R%2==0){
//             return power((N*N)%num,R/2);
//         }else{
//             return (N*power((N*N)%num,R/2))%num;
//         }
//     }

// ----------------------------- METHOD - 2 ----------------------------------- //


// long long power(int num, int rev)
// {
//     long long ans = 1;
//     long long mod = 1e9 + 7;
//     long long pow = num * 1LL;
 
//     while (rev > 0) {
//         // When reverse is odd
//         if (rev & 1) {
//             ans = (ans * pow) % mod;
//         }
//         pow = (pow * pow) % mod;
//         // Shifting right (rev = rev/2 )
//         rev >>= 1;
//     }
//     return ans;
// }

// /////////////////////////////////////////////////////////////// //

// void printNumbers(int num){
//     if(num == 0) return;
//     printNumbers(num-1);
//     cout<<num;
// }


////////////////////////////////////////////////////////////////////////////////

// int sumOfNumbers(int n){
//     if (n==0) return 0;
//     return n + sumOfNumbers(n-1);
// }

////////////////////////////////////////////////////////////////////////////////

// bool isPalindrome(int n){
//     int newNum = 0;
//     int temp=n;
//     while(temp>0){
//         newNum = newNum*10 + temp%10;
//         temp/=10; 
//     }

//     return (newNum==n);
// }

// ---------------------------------------------------------------- //

// bool isPalindrome(string &str, int start,int end) {
//     if(start>=end) return true;
//     bool value = (str[start] == str[end]);
//     // string substr = str.substr(start+1,str.length()-2);
//     return value && isPalindrome(str,start+1,end-1);
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// int sumOfDigits(int n){
//     if(n==0) return 0;
//     return (n%10) + sumOfDigits(n/10); 
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// int ropeCutting(int n, int a, int b, int c){
//     if(n==0) return 0;
//     if(n<0) return -1;
//     int res = max(max(ropeCutting(n-a,a,b,c),ropeCutting(n-b,a,b,c)),ropeCutting(n-c,a,b,c));
//     if(res==-1) return -1;
//     return res = res +1;
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// void subSets(string str,int index=0,string curStr=""){
//     if (str.length()==index) {
//         cout<<curStr<<" ";
//         return;
//         }
//     subSets(str,index+1,curStr);
//     subSets(str,index+1,curStr+str[index]);

// }

//////////////////////////////////////// Incomplete ////////////////////////////////////////////////////////
// vector <string> powerSet(string s,int index=0,string curStr="")
// {
//   vector <string> subSets;
//   if(s.length()==index) {
//     subSets.push_back(curStr);
//     return subSets;
//     }
//   powerSet(s,index+1,curStr);
//   powerSet(s,index+1,curStr+s[index]);
//   return subSets;
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// int towerOfHonai(int n,char from, char aux ,char to){
//   if(n==1) {
//     cout<<"Move disc " << 1 << " from " << from << " to " << to <<endl;
//     return 1;
//   }
//   else{
//     towerOfHonai(n-1,from,to,aux);
//     cout<<"Move disc " << n << " from " << from << " to " << to <<endl;
//     towerOfHonai(n-1,aux,from,to);
//     }
//     return pow(2,n) - 1; 
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// int josephusProblem(int noOfPeople,int k){
//   if(noOfPeople==1) return 1;
//   else return (josephusProblem(noOfPeople-1,k)+k-1)%noOfPeople + 1;
// }

////////////////////////////////////////////////////////////////////////////////////////////////

// Incomplete function
// int subSetSum(vector <int> v,int sum,int index=0,vector<int>* curEl=NULL){
//   if(v.size()== index) return (sum == 0) ? 1 : 0;
//   subSetSum(v,sum,index+1,curEl);
//   curEl.push_back(v[index]);
//   subSetSum(v,sum-v[index],index+1,curEl);
// }
// ------------------------------------------------------------------------------------------------ //

// int subSetSum(int arr[],int n, int sum){
//   if(n==0) return (sum==0) ? 1 : 0;
//   subSetSum(arr,n-1,sum);
//   subSetSum(arr,n-1,sum-arr[n-1]);
// }

////////////////////////////////////////////////////////////////////////////////////////////////
vector <string> possibleWords(int a[],int n,vector<string> words,int index=0){

}

int main(){
    vector <string> keypad = {
    {},{},
    {{'a'},{'b'},{'c'}},
    {{'d'},{'e'},{'f'}},
    {{'g'},{'h'},{'i'}},
    {{'j'},{'k'},{'l'}},
    {{'m'},{'n'},{'o'}},
    {{'p'},{'q'},{'r'},{'s'}},
    {{'t'},{'u'},{'v'}},
    {{'w'},{'x'},{'y'},{'z'}}
    };
  vector <string> words;
  // string input;
  // cin>>input;
  int arr[] = {2,3,4}; 
  possibleWords(arr,3,words);
}