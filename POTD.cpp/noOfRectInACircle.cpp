#include <iostream>

using namespace std;

int rectanglesInCircle(int r) {
    int count = 0;
    for(int i=1;i<=2*r;i++){
        for(int j=1;j<=2*r;j++){
            if(pow(i,2)+pow(j,2) <= 4*pow(r,2)) count++;
        }
    }
    
    return count;
}

int main(){
    cout << rectanglesInCircle(9);
    return 0;
}