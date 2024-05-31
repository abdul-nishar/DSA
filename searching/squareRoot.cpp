#include <iostream>
using namespace std;

int squareRoot(int n) {
    int low = 1, high = n, result = -1;

    while(low<=high){
        int mid = (high+low) / 2;
        if(mid*mid == n) return mid;
        else if(mid*mid > n) high = mid-1;
        else {
            low = mid+1;
            result = mid;
        }
    }

    return result;
}

int main(){
    cout << squareRoot(45);
    return 0;
}