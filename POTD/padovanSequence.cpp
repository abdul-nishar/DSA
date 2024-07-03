#include <iostream>
#include <algorithm>

using namespace std;

int padovanSequence(int n){
    int convertor = pow(10,9) + 7;
    int first = 1, second = 1, third = 1;
    if(n==0 || n==1 || n==2) return 1;
    int temp = 3;
    while(temp <= n){
        temp++;
        int count = third % convertor;
        third = (first % convertor + second % convertor) % convertor;
        first = second % convertor;
        second = count;
    }
    
    return third;
}

int main(){
    cout << padovanSequence(9);
}