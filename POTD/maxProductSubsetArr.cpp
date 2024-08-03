#include <iostream>
#include <vector>

using namespace std;

long long modInverse(long long a, long long m) {
    long long result = 1;
    long long power = m - 2;

    while (power) {
        if (power % 2) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        power /= 2;
    }

    return result;
}

long long int findMaxProduct(vector<int>& arr) {
    const int modulo = 1e9 + 7;
    long long int product = 1;
    int maxNeg = -11, maxVal = -11;
    int negCount = 0, zeroCount = 0;
    
    for (int num : arr) {
        if (num == 0) {
            zeroCount++;
            continue;
        }
        
        if (num < 0) {
            negCount++;
            maxNeg = max(maxNeg, num);
        }
        
        product = (product * (abs(num) % modulo)) % modulo;
        maxVal = max(maxVal, num);
    }
    
    if (zeroCount == arr.size()) return 0;
    if (negCount % 2 != 0) {
        if (negCount == 1 && zeroCount + negCount == arr.size()) {
            if(zeroCount == 0) return maxNeg;
            return 0;
        }
        product = (product * modInverse(abs(maxNeg), modulo)) % modulo;
    }
    
    return product;
}

int main(){
    vector<int> numsArr = {-1,0,-2,4,3};
    cout << findMaxProduct(numsArr) << endl;
    return 0;
}