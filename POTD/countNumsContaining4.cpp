#include <iostream>
#include <vector>
using namespace std;

int countNumsContaining4(int n) {
    int count = 0;
    for(int i= 4; i<=n;i++){
        int temp = i;
        while(temp > 0) {
            if(temp % 10 == 4) {count++;break;}
            else temp/=10;
        }
    }
    return count;
}

int main(){
    cout << countNumsContaining4(445);
    return 0;
}