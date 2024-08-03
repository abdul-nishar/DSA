#include <iostream>

using namespace std;

string smallestNumber(int s, int d) {
    string result = "";
    int sum = s, noOfDigits = d;
    
    if(9*noOfDigits < sum) return "-1";
    
    int i = 1;
    
    while(sum - i > 9*(noOfDigits - 1)) i++;
    
    result += to_string(i);
    sum -= i;
    noOfDigits--;
    
    while(noOfDigits > 0){
        int val = sum - 9*(noOfDigits - 1);
        if(val < 0) val = 0;
        
        sum -= val;
        noOfDigits--;
        
        result += to_string(val);
    }
    
    return result;
}

int main(){
    cout << smallestNumber(25, 7);

    return 0;
}