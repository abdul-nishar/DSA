#include <iostream>
using namespace std;
int sum(int n){
    return n*(n+1)/2;
}
int main(){
    // int sum = 0;
    int input;
    cin>>input;
    // for(int i=1;i<input;++i){
    //     sum += input;
    // }
    // cout<<sum<<endl;
    cout<<sum(input);
}